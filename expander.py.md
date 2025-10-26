---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import sys\nimport os\nimport re\n\nincluded_files = set()\n\nCPSTL_ROOT\
    \ = os.path.abspath(\"\")\n\ndef expand_file(path: str, top_level: bool = False)\
    \ -> str:\n    abs_path = os.path.abspath(path)\n    if abs_path in included_files:\n\
    \        return \"\"\n\n    included_files.add(abs_path)\n\n    output = []\n\
    \    try:\n        with open(abs_path, 'r', encoding='utf-8') as f:\n        \
    \    for line in f:\n                if re.match(r'^\\s*#\\s*pragma\\s+once',\
    \ line):\n                    continue\n\n                match_cpstl = re.match(r'^\\\
    s*#\\s*include\\s+\"cpstl/(.+)\"', line)\n                if match_cpstl:\n  \
    \                  subpath = match_cpstl.group(1)\n                    include_path\
    \ = os.path.join(CPSTL_ROOT, subpath)\n                    output.append(expand_file(include_path,\
    \ top_level=False))\n                else:\n                    output.append(line)\n\
    \    except FileNotFoundError:\n        output.append(f'// File not found: {path}\\\
    n')\n\n    result = ''.join(output).rstrip()\n    return result + '\\n'\n\ndef\
    \ main():\n\targs = sys.argv[1:]\n\tif not args or len(args) > 2:\n\t\tprint(\"\
    Usage: python3 expander.py input.cpp [output.cpp]\")\n\t\tsys.exit(1)\n\n\tinput_path\
    \ = args[0] \n\toutput_path = args[1] if len(args) == 2 else os.path.abspath(\"\
    \")\n\t\n\tif not os.path.isfile(input_path):\n\t\tprint(f\"Error: '{input_path}'\
    \ does not exist.\")\n\t\tsys.exit(1) \n\t\n\tresult = expand_file(input_path,\
    \ top_level=True)\n\t\n\twith open(output_path, 'w', encoding='utf-8') as f: \n\
    \t\tf.write(result)\n\t\n\tprint(f\"Expanded: {input_path} -> {output_path}\"\
    )\n\nif __name__ == \"__main__\":\n\tmain()\n"
  dependsOn: []
  isVerificationFile: false
  path: expander.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: expander.py
layout: document
redirect_from:
- /library/expander.py
- /library/expander.py.html
title: expander.py
---
