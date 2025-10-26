import sys
import os
import re

included_files = set()

CPSTL_ROOT = os.path.abspath("/home/mofuuni1129/kyopro/atc/cp-STL/cpstl")

def expand_file(path: str, top_level: bool = False) -> str:
    abs_path = os.path.abspath(path)
    if abs_path in included_files:
        return ""

    included_files.add(abs_path)

    output = []
    try:
        with open(abs_path, 'r', encoding='utf-8') as f:
            for line in f:
                if re.match(r'^\s*#\s*pragma\s+once', line):
                    continue

                match_cpstl = re.match(r'^\s*#\s*include\s+"cpstl/(.+)"', line)
                if match_cpstl:
                    subpath = match_cpstl.group(1)
                    include_path = os.path.join(CPSTL_ROOT, subpath)
                    output.append(expand_file(include_path, top_level=False))
                else:
                    output.append(line)
    except FileNotFoundError:
        output.append(f'// File not found: {path}\n')

    result = ''.join(output).rstrip()
    return result + '\n'

def main():
	args = sys.argv[1:]
	if not args or len(args) > 2:
		print("Usage: python3 expander.py input.cpp [output.cpp]")
		sys.exit(1)

	input_path = args[0] 
	output_path = args[1] if len(args) == 2 else os.path.abspath("/home/mofuuni1129/kyopro/atc/cp-STL/e.cpp")
	
	if not os.path.isfile(input_path):
		print(f"Error: '{input_path}' does not exist.")
		sys.exit(1) 
	
	result = expand_file(input_path, top_level=True)
	
	with open(output_path, 'w', encoding='utf-8') as f: 
		f.write(result)
	
	print(f"Expanded: {input_path} -> {output_path}")

if __name__ == "__main__":
	main()