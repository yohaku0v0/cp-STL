---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpstl/other/Fastio.hpp
    title: cpstl/other/Fastio.hpp
  - icon: ':heavy_check_mark:'
    path: cpstl/other/Template.hpp
    title: cpstl/other/Template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: cpstl/ds/Segtree.hpp
    title: cpstl/ds/Segtree.hpp
  - icon: ':heavy_check_mark:'
    path: cpstl/other/Fastio.hpp
    title: cpstl/other/Fastio.hpp
  - icon: ':heavy_check_mark:'
    path: cpstl/other/Template.hpp
    title: cpstl/other/Template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/other/lc-Many-A+B-128bit-Fastio.test.cpp
    title: verify/other/lc-Many-A+B-128bit-Fastio.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"cpstl/other/Template.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"cpstl/other/Fastio.hpp\"\n\nnamespace cpstd {\n\nnamespace Fastio {\n\n\
    static constexpr const uint32_t BUF_SIZE = 1 << 17;\nchar ibuf[BUF_SIZE], obuf[BUF_SIZE],\
    \ out[100];\nuint32_t pil = 0, pir = 0, por = 0;\n\nstruct Pre {\n\tchar num[10000][4];\n\
    \n\tconstexpr Pre() : num() {\n\t\tfor (int i = 0; i < 10000; ++i) {\n\t\t\tint\
    \ n = i;\n\t\t\tfor (int j = 3; j >= 0; --j) {\n\t\t\t\tnum[i][j] = n % 10 | '0';\n\
    \t\t\t\tn /= 10;\n\t\t\t}\n\t\t}\n\t}\n} constexpr pre;\n\ninline void load()\
    \ {\n\tstd::memcpy(ibuf, ibuf + pil, pir - pil);\n\tpir = pir - pil + std::fread(ibuf\
    \ + pir - pil, 1, BUF_SIZE - pir + pil, stdin);\n\tpil = 0;\n\tif (pir < BUF_SIZE)\
    \ ibuf[pir++] = '\\n';\n}\n\ninline void flush() {\n\tfwrite(obuf, 1, por, stdout);\n\
    \tpor = 0;\n}\n\nvoid _input(char &dest) {\n\tdo {\n\t\tif (pil + 1 > pir) load();\n\
    \t\tdest = ibuf[pil++];\n\t} while (std::isspace(dest));\n}\n\nvoid _input(std::string\
    \ &dest) {\n\tdest.clear();\n\tchar c;\n\tdo {\n\t\tif (pil + 1 > pir) load();\n\
    \t\tc = ibuf[pil++];\n\t} while (std::isspace(c));\n\tdo {\n\t\tdest += c;\n\t\
    \tif (pil == pir) load();\n\t\tc = ibuf[pil++];\n\t} while (!std::isspace(c));\n\
    }\n\nvoid _input(float &dest) {\n\tstd::string s;\n\t_input(s);\n\tdest = std::stof(s);\n\
    }\n\nvoid _input(double &dest) {\n\tstd::string s;\n\t_input(s);\n\tdest = std::stod(s);\n\
    }\n\nvoid _input(long double &dest) {\n\tstd::string s;\n\t_input(s);\n\tdest\
    \ = std::stold(s);\n}\n\ntemplate <typename T>\nvoid input_int(T &x) {\n\tif (pil\
    \ + 100 > pir) load();\n\tchar c;\n\tdo {\n\t\tc = ibuf[pil++];\n\t} while (c\
    \ < '-');\n\tbool minus = 0;\n\tif constexpr (std::is_signed<T>::value || std::is_same_v<T,\
    \ __int128_t>) {\n\t\tif (c == '-') minus = 1, c = ibuf[pil++];\n\t}\n\tx = 0;\n\
    \twhile (c >= '0') x = x * 10 + (c & 15), c = ibuf[pil++];\n\tif constexpr (std::is_signed<T>::value\
    \ || std::is_same_v<T, __int128_t>) {\n\t\tif (minus) x = -x;\n\t}\n}\n\nvoid\
    \ _input(int &dest) { input_int(dest); }\nvoid _input(unsigned int &dest) { input_int(dest);\
    \ }\nvoid _input(long long &dest) { input_int(dest); }\nvoid _input(unsigned long\
    \ long &dest) { input_int(dest); }\nvoid _input(__int128 &dest) { input_int(dest);\
    \ }\nvoid _input(unsigned __int128 &dest) { input_int(dest); }\n\ntemplate <uint32_t\
    \ m>\nvoid _input(cpstd::StaticModint<m> &dest) { long long a; _input(a); dest\
    \ = a; }\n\ntemplate <typename T, typename U>\nvoid _input(std::pair<T, U> &dest)\
    \ { _input(dest.first), _input(dest.second); }\n\ntemplate <std::size_t N = 0,\
    \ typename T>\nvoid input_tuple(T &t) {\n\tif constexpr (N < std::tuple_size<T>::value)\
    \ {\n\t\tauto &x = std::get<N>(t);\n\t\tinput(x);\n\t\tinput_tuple<N + 1>(t);\n\
    \t}\n}\n\ntemplate <typename... T>\nvoid _input(std::tuple<T...> &dest) { input_tuple(dest);\
    \ }\n\ntemplate <std::size_t N = 0, typename T>\nvoid _input(std::array<T, N>\
    \ &dest) { for (auto &e : dest) _input(e); }\n\ntemplate <typename T>\nvoid _input(std::vector<T>\
    \ &dest) { for (auto &e : dest) _input(e); }\n\nvoid input() {}\n\n// \u5404\u5F15\
    \u6570\u306B\u5165\u529B\ntemplate <typename H, typename... T>\nvoid input(H &desth,\
    \ T &... destt) { _input(desth), input(destt...); }\n\nvoid _print(const char\
    \ tg) {\n\tif (por == BUF_SIZE) flush();\n\tobuf[por++] = tg;\n}\n\nvoid _print(const\
    \ std::string tg) { for (char c : tg) _print(c); }\n\nvoid _print(const char *tg)\
    \ {\n\tstd::size_t len = std::strlen(tg);\n\tfor (std::size_t i = 0; i < len;\
    \ ++i) _print(tg[i]);\n}\n\ntemplate <typename T>\nvoid print_int(T x) {\n\tif\
    \ (por > BUF_SIZE - 100) flush();\n\tif (x < 0) obuf[por++] = '-', x = -x;\n\t\
    int outi;\n\tfor (outi = 96; x >= 10000; outi -= 4) {\n\t\tstd::memcpy(out + outi,\
    \ pre.num[x % 10000], 4);\n\t\tx /= 10000;\n\t}\n\tif (x >= 1000) {\n\t\tstd::memcpy(obuf\
    \ + por, pre.num[x], 4);\n\t\tpor += 4;\n\t}\n\telse if (x >= 100) {\n\t\tstd::memcpy(obuf\
    \ + por, pre.num[x] + 1, 3);\n\t\tpor += 3;\n\t}\n\telse if (x >= 10) {\n\t\t\
    int q = (x * 103) >> 10;\n\t\tobuf[por] = q | '0';\n\t\tobuf[por + 1] = (x - q\
    \ * 10) | '0';\n\t\tpor += 2;\n\t}\n\telse obuf[por++] = x | '0';\n\tstd::memcpy(obuf\
    \ + por, out + outi + 4, 96 - outi);\n\tpor += 96 - outi;\n}\n\ntemplate <typename\
    \ T>\nvoid print_real(T tg) {\n\tstd::ostringstream oss;\n\toss << std::fixed\
    \ << std::setprecision(15) << double(tg);\n\tstd::string s = oss.str();\n\t_print(s);\n\
    }\n\nvoid _print(int tg) { print_int(tg); }\nvoid _print(unsigned int tg) { print_int(tg);\
    \ }\nvoid _print(long long tg) { print_int(tg); }\nvoid _print(unsigned long long\
    \ tg) { print_int(tg); }\nvoid _print(__int128 tg) { print_int(tg); }\nvoid _print(unsigned\
    \ __int128 tg) { print_int(tg); }\nvoid _print(float tg) { print_real(tg); }\n\
    void _print(double tg) { print_real(tg); }\nvoid _print(long double tg) { print_real(tg);\
    \ }\n\ntemplate <uint32_t m>\nvoid _print(cpstd::StaticModint<m> tg) { print_int(tg.val());\
    \ }\n\ntemplate <typename T, typename U>\nvoid _print(const std::pair<T, U> tg)\
    \ {\n\t_print(tg.first);\n\t_print(' ');\n\t_print(tg.second);\n}\n\ntemplate\
    \ <std::size_t N = 0, typename T>\nvoid print_tuple(const T tg) {\n\tif constexpr\
    \ (N < std::tuple_size<T>::value) {\n\t\tif constexpr (N > 0) _print(' ');\n\t\
    \tconst auto x = std::get<N>(tg);\n\t\t_print(x);\n\t\tprint_tuple<N + 1>(tg);\n\
    \t}\n}\n\ntemplate <typename... T>\nvoid _print(std::tuple<T...> tg) { print_tuple(tg);\
    \ }\n\ntemplate <typename T, std::size_t N>\nvoid _print(const std::array<T, N>\
    \ tg) {\n\tauto len = tg.size();\n\tfor (std::size_t i = 0; i < len; ++i) {\n\t\
    \tif (i) _print(' ');\n\t\t_print(tg[i]);\n\t}\n}\n\ntemplate <typename T>\nvoid\
    \ _print(const std::vector<T> tg) {\n\tauto  len = tg.size();\n\tfor (std::size_t\
    \ i = 0; i < len; ++i) {\n\t\tif (i) _print(' ');\n\t\t_print(tg[i]);\n\t}\n}\n\
    \nvoid print() {}\n\ntemplate <typename H, typename... T>\nvoid print(H &&tgh,\
    \ T &&... tgt) {\n\t_print(tgh);\n\tif constexpr (sizeof...(tgt)) {\n\t\t_print('\
    \ ');\n\t\tprint(std::forward<T>(tgt)...);\n\t}\n}\n\nvoid println() { _print('\\\
    n'); }\n\ntemplate <typename H, typename... T>\nvoid println(H &&tgh, T &&...\
    \ tgt) {\n\t_print(tgh);\n\tif (sizeof...(tgt)) _print(' ');\n\tprintln(std::forward<T>(tgt)...);\n\
    }\n\nvoid print_ns() {}\n\ntemplate <typename H, typename... T>\nvoid print_ns(H\
    \ &&tgh, T &&... tgt) {\n\t_print(tgh);\n\tprint_ns(std::forward<T>(tgt)...);\n\
    }\n\nvoid println_ns() { _print('\\n'); }\n\ntemplate <typename H, typename...\
    \ T>\nvoid println_ns(H &&tgh, T &&... tgt) {\n\t_print(tgh);\n\tprintln_ns(std::forward<T>(tgt)...);\n\
    }\n\nvoid __attribute__((destructor)) _d() { flush(); }\n\n};\n\nusing Fastio::input;\n\
    using Fastio::print;\nusing Fastio::println;\nusing Fastio::print_ns;\nusing Fastio::println_ns;\n\
    using Fastio::flush;\n\n};\n#line 3 \"cpstl/math/StaticModint.hpp\"\n\nnamespace\
    \ cpstd {\n\ntemplate <uint32_t m>\nstruct StaticModint {\n\tprivate:\n\tusing\
    \ mint = StaticModint;\n\tuint32_t _v = 0;\n\n\tstatic constexpr bool is_prime\
    \ = []() -> bool {\n\t\tif (m == 1) return false;\n\t\tif (m == 2 || m == 7 ||\
    \ m == 61) return true;\n\t\tif (!(m & 1)) return false;\n\t\tuint32_t d = m -\
    \ 1;\n\t\twhile (!(d & 1)) d >>= 1;\n\t\tfor (uint32_t a : {2, 7, 61}) {\n\t\t\
    \tuint32_t t = d;\n\t\t\tmint y = mint(a).pow(t);\n\t\t\twhile (t != m - 1 &&\
    \ y != 1 && y != m - 1) {\n\t\t\t\ty *= y;\n\t\t\t\tt <<= 1;\n\t\t\t}\n\t\t\t\
    if (y != m - 1 && !(t & 1)) return false;\n\t\t}\n\t\treturn true;\n\t}();\n\t\
    \n\tstatic constexpr std::pair<int32_t, int32_t> inv_gcd(int32_t a, int32_t b)\
    \ {\n\t\tif (a == 0) return {b, 0};\n\t\tint32_t s = b, t = a, m0 = 0, m1 = 1;\n\
    \t\twhile (t) {\n\t\t\tconst int32_t q = s / t;\n\t\t\ts -= t * q, std::swap(s,\
    \ t);\n\t\t\tm0 -= m1 * q, std::swap(m0, m1);\n\t\t}\n\t\tif (m0 < 0) m0 += b\
    \ / s;\n\t\treturn {s, m0};\n\t}\n\n\tpublic:\n\tconstexpr StaticModint() {}\n\
    \ttemplate <typename T>\n\tconstexpr StaticModint(T v) {\n\t\tstatic_assert(std::is_integral_v<T>,\
    \ \"T is not integral type.\");\n\t\tif constexpr (std::is_signed_v<T>) {\n\t\t\
    \tint64_t x = int64_t(v % int64_t(m));\n\t\t\tif (x < 0) x += m;\n\t\t\t_v = uint32_t(x);\n\
    \t\t}\n\t\telse _v = uint32_t(v % m);\n\t}\n\n\tstatic constexpr mint raw(uint32_t\
    \ v) { mint a; a._v = v; return a; }\n\n\tstatic constexpr uint32_t mod() { return\
    \ m; }\n\n\tconstexpr uint32_t val() const { return _v; }\n\n\tconstexpr mint&\
    \ operator++() { return *this += 1; }\n\n\tconstexpr mint operator++(int) { mint\
    \ res = *this; ++*this; return res; }\n\n\tconstexpr mint& operator--() { return\
    \ *this -= 1; }\n\n\tconstexpr mint operator--(int) { mint res = *this; --*this;\
    \ return res; }\n\n\tconstexpr mint& operator+=(mint rhs) {\n\t\tif (_v >= m -\
    \ rhs._v) _v -= m;\n\t\t_v += rhs._v;\n\t\treturn *this;\n\t}\n\n\tconstexpr mint&\
    \ operator-=(mint rhs) {\n\t\tif (_v < rhs._v) _v += m;\n\t\t_v -= rhs._v;\n\t\
    \treturn *this;\n\t}\n\n\tconstexpr mint& operator*=(mint rhs) { return *this\
    \ = *this * rhs; }\n\n\tconstexpr mint& operator/=(mint rhs) { return *this *=\
    \ rhs.inv(); }\n\n\tconstexpr mint operator+() const { return *this; }\n\n\tconstexpr\
    \ mint operator-() const { return mint{} - *this; }\n\n\tconstexpr mint pow(long\
    \ long n) const {\n\t\tassert(0 <= n);\n\t\tif (n == 0) return 1;\n\t\tmint x\
    \ = *this, r = 1;\n\t\twhile (n > 0) {\n\t\t\tif (n & 1) r *= x;\n\t\t\tx *= x;\n\
    \t\t\tn >>= 1;\n\t\t\tif (!n) return r;\n\t\t}\n\t\treturn r;\n\t}\n\n\tconstexpr\
    \ mint inv() const {\n\t\tif constexpr (is_prime) {\n\t\t\tassert(_v);\n\t\t\t\
    return pow(m - 2);\n\t\t}\n\t\telse {\n\t\t\tauto eg = inv_gcd(_v, m);\n\t\t\t\
    assert(eg.first == 1);\n\t\t\treturn eg.second;\n\t\t}\n\t}\n\n\tfriend constexpr\
    \ mint operator+(mint lhs, mint rhs) { return lhs += rhs; }\n\n\tfriend constexpr\
    \ mint operator-(mint lhs, mint rhs) { return lhs -= rhs; }\n\n\tfriend constexpr\
    \ mint operator*(mint lhs, mint rhs) { return uint64_t(lhs._v) * rhs._v; }\n\t\
    \n\tfriend constexpr mint operator/(mint lhs, mint rhs) { return lhs /= rhs; }\n\
    \n\tfriend constexpr bool operator==(mint lhs, mint rhs) { return lhs._v == rhs._v;\
    \ }\n\n\tfriend constexpr bool operator!=(mint lhs, mint rhs) { return lhs._v\
    \ != rhs._v; }\n};\n\nusing Modint998244353 = StaticModint<998244353>;\n\nconstexpr\
    \ Modint998244353 operator\"\"_M(unsigned long long x) { return x; }\n};\n"
  code: "#pragma once\n#include \"cpstl/other/Template.hpp\"\n\nnamespace cpstd {\n\
    \ntemplate <uint32_t m>\nstruct StaticModint {\n\tprivate:\n\tusing mint = StaticModint;\n\
    \tuint32_t _v = 0;\n\n\tstatic constexpr bool is_prime = []() -> bool {\n\t\t\
    if (m == 1) return false;\n\t\tif (m == 2 || m == 7 || m == 61) return true;\n\
    \t\tif (!(m & 1)) return false;\n\t\tuint32_t d = m - 1;\n\t\twhile (!(d & 1))\
    \ d >>= 1;\n\t\tfor (uint32_t a : {2, 7, 61}) {\n\t\t\tuint32_t t = d;\n\t\t\t\
    mint y = mint(a).pow(t);\n\t\t\twhile (t != m - 1 && y != 1 && y != m - 1) {\n\
    \t\t\t\ty *= y;\n\t\t\t\tt <<= 1;\n\t\t\t}\n\t\t\tif (y != m - 1 && !(t & 1))\
    \ return false;\n\t\t}\n\t\treturn true;\n\t}();\n\t\n\tstatic constexpr std::pair<int32_t,\
    \ int32_t> inv_gcd(int32_t a, int32_t b) {\n\t\tif (a == 0) return {b, 0};\n\t\
    \tint32_t s = b, t = a, m0 = 0, m1 = 1;\n\t\twhile (t) {\n\t\t\tconst int32_t\
    \ q = s / t;\n\t\t\ts -= t * q, std::swap(s, t);\n\t\t\tm0 -= m1 * q, std::swap(m0,\
    \ m1);\n\t\t}\n\t\tif (m0 < 0) m0 += b / s;\n\t\treturn {s, m0};\n\t}\n\n\tpublic:\n\
    \tconstexpr StaticModint() {}\n\ttemplate <typename T>\n\tconstexpr StaticModint(T\
    \ v) {\n\t\tstatic_assert(std::is_integral_v<T>, \"T is not integral type.\");\n\
    \t\tif constexpr (std::is_signed_v<T>) {\n\t\t\tint64_t x = int64_t(v % int64_t(m));\n\
    \t\t\tif (x < 0) x += m;\n\t\t\t_v = uint32_t(x);\n\t\t}\n\t\telse _v = uint32_t(v\
    \ % m);\n\t}\n\n\tstatic constexpr mint raw(uint32_t v) { mint a; a._v = v; return\
    \ a; }\n\n\tstatic constexpr uint32_t mod() { return m; }\n\n\tconstexpr uint32_t\
    \ val() const { return _v; }\n\n\tconstexpr mint& operator++() { return *this\
    \ += 1; }\n\n\tconstexpr mint operator++(int) { mint res = *this; ++*this; return\
    \ res; }\n\n\tconstexpr mint& operator--() { return *this -= 1; }\n\n\tconstexpr\
    \ mint operator--(int) { mint res = *this; --*this; return res; }\n\n\tconstexpr\
    \ mint& operator+=(mint rhs) {\n\t\tif (_v >= m - rhs._v) _v -= m;\n\t\t_v +=\
    \ rhs._v;\n\t\treturn *this;\n\t}\n\n\tconstexpr mint& operator-=(mint rhs) {\n\
    \t\tif (_v < rhs._v) _v += m;\n\t\t_v -= rhs._v;\n\t\treturn *this;\n\t}\n\n\t\
    constexpr mint& operator*=(mint rhs) { return *this = *this * rhs; }\n\n\tconstexpr\
    \ mint& operator/=(mint rhs) { return *this *= rhs.inv(); }\n\n\tconstexpr mint\
    \ operator+() const { return *this; }\n\n\tconstexpr mint operator-() const {\
    \ return mint{} - *this; }\n\n\tconstexpr mint pow(long long n) const {\n\t\t\
    assert(0 <= n);\n\t\tif (n == 0) return 1;\n\t\tmint x = *this, r = 1;\n\t\twhile\
    \ (n > 0) {\n\t\t\tif (n & 1) r *= x;\n\t\t\tx *= x;\n\t\t\tn >>= 1;\n\t\t\tif\
    \ (!n) return r;\n\t\t}\n\t\treturn r;\n\t}\n\n\tconstexpr mint inv() const {\n\
    \t\tif constexpr (is_prime) {\n\t\t\tassert(_v);\n\t\t\treturn pow(m - 2);\n\t\
    \t}\n\t\telse {\n\t\t\tauto eg = inv_gcd(_v, m);\n\t\t\tassert(eg.first == 1);\n\
    \t\t\treturn eg.second;\n\t\t}\n\t}\n\n\tfriend constexpr mint operator+(mint\
    \ lhs, mint rhs) { return lhs += rhs; }\n\n\tfriend constexpr mint operator-(mint\
    \ lhs, mint rhs) { return lhs -= rhs; }\n\n\tfriend constexpr mint operator*(mint\
    \ lhs, mint rhs) { return uint64_t(lhs._v) * rhs._v; }\n\t\n\tfriend constexpr\
    \ mint operator/(mint lhs, mint rhs) { return lhs /= rhs; }\n\n\tfriend constexpr\
    \ bool operator==(mint lhs, mint rhs) { return lhs._v == rhs._v; }\n\n\tfriend\
    \ constexpr bool operator!=(mint lhs, mint rhs) { return lhs._v != rhs._v; }\n\
    };\n\nusing Modint998244353 = StaticModint<998244353>;\n\nconstexpr Modint998244353\
    \ operator\"\"_M(unsigned long long x) { return x; }\n};\n"
  dependsOn:
  - cpstl/other/Template.hpp
  - cpstl/other/Fastio.hpp
  isVerificationFile: false
  path: cpstl/math/StaticModint.hpp
  requiredBy:
  - cpstl/ds/Segtree.hpp
  - cpstl/other/Template.hpp
  - cpstl/other/Fastio.hpp
  timestamp: '2025-09-09 02:59:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/other/lc-Many-A+B-128bit-Fastio.test.cpp
documentation_of: cpstl/math/StaticModint.hpp
layout: document
redirect_from:
- /library/cpstl/math/StaticModint.hpp
- /library/cpstl/math/StaticModint.hpp.html
title: cpstl/math/StaticModint.hpp
---
