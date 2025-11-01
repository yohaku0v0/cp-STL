---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: cpstl/ds/LazySegtree.hpp
    title: cpstl/ds/LazySegtree.hpp
  - icon: ':x:'
    path: cpstl/math/StaticModint.hpp
    title: cpstl/math/StaticModint.hpp
  - icon: ':x:'
    path: cpstl/other/Fastio.hpp
    title: cpstl/other/Fastio.hpp
  - icon: ':x:'
    path: cpstl/other/Template.hpp
    title: cpstl/other/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"verify/ds/lc-Range-Affine-Range-sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n#line\
    \ 2 \"cpstl/other/Template.hpp\"\n#include <bits/stdc++.h>\n#line 3 \"cpstl/math/StaticModint.hpp\"\
    \n\nnamespace cpstd {\n\ntemplate <uint32_t m>\nstruct StaticModint {\n\tprivate:\n\
    \tusing mint = StaticModint;\n\tuint32_t _v = 0;\n\n\tstatic constexpr bool is_prime\
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
    \ Modint998244353 operator\"\"_M(unsigned long long x) { return x; }\n};\n#line\
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
    \ }\nvoid _input(long &dest) { input_int(dest); }\nvoid _input(unsigned long &dest)\
    \ { input_int(dest); }\nvoid _input(long long &dest) { input_int(dest); }\nvoid\
    \ _input(unsigned long long &dest) { input_int(dest); }\nvoid _input(__int128\
    \ &dest) { input_int(dest); }\nvoid _input(unsigned __int128 &dest) { input_int(dest);\
    \ }\n\ntemplate <uint32_t m>\nvoid _input(cpstd::StaticModint<m> &dest) { long\
    \ long a; _input(a); dest = a; }\n\ntemplate <typename T, typename U>\nvoid _input(std::pair<T,\
    \ U> &dest) { _input(dest.first), _input(dest.second); }\n\ntemplate <std::size_t\
    \ N = 0, typename T>\nvoid input_tuple(T &t) {\n\tif constexpr (N < std::tuple_size<T>::value)\
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
    \ }\nvoid _print(long tg) { print_int(tg); }\nvoid _print(unsigned long tg) {\
    \ print_int(tg);}\nvoid _print(long long tg) { print_int(tg); }\nvoid _print(unsigned\
    \ long long tg) { print_int(tg); }\nvoid _print(__int128 tg) { print_int(tg);\
    \ }\nvoid _print(unsigned __int128 tg) { print_int(tg); }\nvoid _print(float tg)\
    \ { print_real(tg); }\nvoid _print(double tg) { print_real(tg); }\nvoid _print(long\
    \ double tg) { print_real(tg); }\n\ntemplate <uint32_t m>\nvoid _print(cpstd::StaticModint<m>\
    \ tg) { print_int(tg.val()); }\n\ntemplate <typename T, typename U>\nvoid _print(const\
    \ std::pair<T, U> tg) {\n\t_print(tg.first);\n\t_print(' ');\n\t_print(tg.second);\n\
    }\n\ntemplate <std::size_t N = 0, typename T>\nvoid print_tuple(const T tg) {\n\
    \tif constexpr (N < std::tuple_size<T>::value) {\n\t\tif constexpr (N > 0) _print('\
    \ ');\n\t\tconst auto x = std::get<N>(tg);\n\t\t_print(x);\n\t\tprint_tuple<N\
    \ + 1>(tg);\n\t}\n}\n\ntemplate <typename... T>\nvoid _print(std::tuple<T...>\
    \ tg) { print_tuple(tg); }\n\ntemplate <typename T, std::size_t N>\nvoid _print(const\
    \ std::array<T, N> tg) {\n\tauto len = tg.size();\n\tfor (std::size_t i = 0; i\
    \ < len; ++i) {\n\t\tif (i) _print(' ');\n\t\t_print(tg[i]);\n\t}\n}\n\ntemplate\
    \ <typename T>\nvoid _print(const std::vector<T> tg) {\n\tauto  len = tg.size();\n\
    \tfor (std::size_t i = 0; i < len; ++i) {\n\t\tif (i) _print(' ');\n\t\t_print(tg[i]);\n\
    \t}\n}\n\nvoid print() {}\n\ntemplate <typename H, typename... T>\nvoid print(H\
    \ &&tgh, T &&... tgt) {\n\t_print(tgh);\n\tif constexpr (sizeof...(tgt)) {\n\t\
    \t_print(' ');\n\t\tprint(std::forward<T>(tgt)...);\n\t}\n}\n\nvoid println()\
    \ { _print('\\n'); }\n\ntemplate <typename H, typename... T>\nvoid println(H &&tgh,\
    \ T &&... tgt) {\n\t_print(tgh);\n\tif (sizeof...(tgt)) _print(' ');\n\tprintln(std::forward<T>(tgt)...);\n\
    }\n\nvoid print_ns() {}\n\ntemplate <typename H, typename... T>\nvoid print_ns(H\
    \ &&tgh, T &&... tgt) {\n\t_print(tgh);\n\tprint_ns(std::forward<T>(tgt)...);\n\
    }\n\nvoid println_ns() { _print('\\n'); }\n\ntemplate <typename H, typename...\
    \ T>\nvoid println_ns(H &&tgh, T &&... tgt) {\n\t_print(tgh);\n\tprintln_ns(std::forward<T>(tgt)...);\n\
    }\n\nvoid __attribute__((destructor)) _d() { flush(); }\n\n};\n\nusing Fastio::input;\n\
    using Fastio::print;\nusing Fastio::println;\nusing Fastio::print_ns;\nusing Fastio::println_ns;\n\
    using Fastio::flush;\n\n};\n#line 5 \"cpstl/other/Template.hpp\"\n\nusing i32\
    \ = std::int32_t;\nusing i64 = std::int64_t;\nusing i128 = __int128_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\nusing u128 = unsigned __int128_t;\n\
    using usize = std::size_t;\n\nconstexpr i64 SafeMod(i64 x, u64 m) {\n\tx %= m;\n\
    \tif (x < 0) x += m;\n\treturn x;\n}\n\nconstexpr u64 ModPow(i64 x, u64 n, u64\
    \ m) {\n\tif (m == 1) return 0;\n\tu64 res = 1, a = SafeMod(x, m);\n\twhile (n)\
    \ {\n\t\tif (n & 1) res = res * a % m;\n\t\ta = a * a % m;\n\t\tn >>= 1;\n\t}\n\
    \treturn res;\n}\n\nconstexpr u128 ModPow_u128(i128 x, u128 n, u128 m) {\n\tif\
    \ (m == 1) return 0;\n\tu128 res = 1, a = (x < 0 ? x % m + m : x % m);\n\twhile\
    \ (n) {\n\t\tif (n & 1) res = res * a % m;\n\t\ta = a * a % m;\n\t\tn >>= 1;\n\
    \t}\n\treturn res;\n}\n\nconstexpr u64 Binarygcd(u64 a, u64 b) {\n\tif (!a ||\
    \ !b) return a | b;\n\tconst i32 n = __builtin_ctzll(a | b);\n\ta >>= __builtin_ctzll(a),\
    \ b >>= __builtin_ctzll(b);\n\twhile (a != b) {\n\t\tif (a > b) a -= b, b >>=\
    \ __builtin_ctzll(b);\n\t\telse b -= a, a >>= __builtin_ctzll(a);\n\t}\n\treturn\
    \ a << n;\n}\n\nvoid YN(bool flag) {\n\tcpstd::println((flag ? \"Yes\" : \"No\"\
    ));\n}\n\ntemplate <typename T, class... Args>\nconstexpr bool chmax(T &x, const\
    \ Args&... args) {\n\tT old = x;\n\tfor (auto y : {args...}) x = std::max(x, y);\n\
    \treturn x == old;\n}\n\ntemplate <typename T, class... Args>\nconstexpr bool\
    \ chmin(T &x, const Args&... args) {\n\tT old = x;\n\tfor (auto y : {args...})\
    \ x = std::min(x, y);\n\treturn x == old;\n}\n\ni64 isqrt(const i64 n) {\n\tassert(n\
    \ >= 0);\n\tif (n >= 9223372030926249001LL) return 3037000499LL;\n\ti64 res =\
    \ std::sqrt(n);\n\twhile (res * res > x) --res;\n\twhile ((res + 1) * (res + 1)\
    \ <= n) ++res;\n\treturn res;\n}\n#line 3 \"cpstl/ds/LazySegtree.hpp\"\n\nnamespace\
    \ cpstd {\n\ntemplate <\n\ttypename S,\n\tauto operation,\n\tauto identity_elem,\n\
    \ttypename F,\n\tauto mapping,\n\tauto composition,\n\tauto identity_map\n>\n\
    class LazySegtree {\n\tprivate:\n\tstd::vector<S> dat;\n\tstd::vector<F> lazy;\n\
    \tusize n, sz, log;\n\n\tvoid propagate(usize idx, const F &f) {\n\t\tdat[idx]\
    \ = mapping(f, dat[idx]);\n\t\tif (idx < sz) lazy[idx] = composition(f, lazy[idx]);\n\
    \t}\n\n\tvoid pushdown(usize idx) {\n\t\tif (lazy[idx] == identity_map()) return;\n\
    \t\tpropagate(idx * 2, lazy[idx]);\n\t\tpropagate(idx * 2 + 1, lazy[idx]);\n\t\
    \tlazy[idx] = identity_map();\n\t}\n\n\tvoid merge(usize idx) { dat[idx] = operation(dat[idx\
    \ * 2], dat[idx * 2 + 1]); }\n\n\tvoid pushup(usize idx) {\n\t\twhile (idx > 1)\
    \ {\n\t\t\tidx >>= 1;\n\t\t\tmerge(idx);\n\t\t}\n\t}\n\n\tpublic:\n\tLazySegtree()\
    \ {}\n\n\texplicit LazySegtree(usize N) : LazySegtree(std::vector<S>(N, identity_elem()))\
    \ {}\n\n\tLazySegtree(usize N, const S &x) : LazySegtree(std::vector<S>(N, x))\
    \ {}\n\n\texplicit LazySegtree(const std::vector<S> &v) : n(v.size()) {\n\t\t\
    sz = std::bit_ceil(n);\n\t\tlog = std::bit_width(sz - 1);\n\t\tdat.assign(sz *\
    \ 2, identity_elem());\n\t\tlazy.assign(sz * 2, identity_map());\n\t\tfor (usize\
    \ i = 0; i < n; ++i) dat[i + sz] = v[i];\n\t\tfor (usize i = sz - 1; i >= 1; --i)\
    \ dat[i] = operation(dat[i * 2], dat[i * 2 + 1]);\n\t}\n\n\tvoid set(usize idx,\
    \ const S &x) {\n\t\tassert(0 <= idx && idx < n);\n\t\tidx += sz;\n\t\tfor (usize\
    \ i = log; i >= 1; --i) pushdown(idx >> i);\n\t\tdat[idx] = x;\n\t\tpushup(idx);\n\
    \t}\n\n\tvoid add(usize idx, const S &x) {\n\t\tassert(0 <= idx && idx < n);\n\
    \t\tidx += sz;\n\t\tfor (usize i = log; i >= 1; --i) pushdown(idx >> i);\n\t\t\
    dat[idx] += x;\n\t\tpushup(idx);\n\t}\n\n\tvoid apply(usize idx, const F &f) {\n\
    \t\tassert(0 <= idx && idx < n);\n\t\tidx += sz;\n\t\tfor (usize i = log; i >=\
    \ 1; --i) pushdown(idx >> i);\n\t\tdat[idx] = mapping(f, dat[idx]);\n\t\tpushup(idx);\n\
    \t}\n\n\tvoid apply(usize l, usize r, const F &f) {\n\t\tassert(0 <= l && l <=\
    \ r && r <= n);\n\t\tif (l == r) return;\n\t\tl += sz, r += sz;\n\t\tfor (usize\
    \ i = log; i >= 1; --i) {\n\t\t\tif (((l >> i) << i) != l) pushdown(l >> i);\n\
    \t\t\tif (((r >> i) << i) != r) pushdown((r - 1) >> i);\n\t\t}\n\t\tfor (usize\
    \ l2 = l, r2 = r; l2 < r2; l2 >>= 1, r2 >>= 1) {\n\t\t\tif (l2 & 1) propagate(l2++,\
    \ f);\n\t\t\tif (r2 & 1) propagate(--r2, f);\n\t\t}\n\t\tfor (usize i = 1; i <=\
    \ log; ++i) {\n\t\t\tif (((l >> i) << i) != l) merge(l >> i);\n\t\t\tif (((r >>\
    \ i) << i) != r) merge((r - 1) >> i);\n\t\t}\n\t}\n\n\tS get(usize idx) {\n\t\t\
    assert(0 <= idx && idx < n);\n\t\tidx += sz;\n\t\tfor (usize i = log; i >= 1;\
    \ --i) pushdown(idx >> i);\n\t\treturn dat[idx];\n\t}\n\n\tS operator[](usize\
    \ idx) noexcept {\n\t\tidx += sz;\n\t\tfor (usize i = log; i >= 1; --i) pushdown(idx\
    \ >> i);\n\t\treturn dat[idx];\n\t}\n\n\tS fold(usize l, usize r) {\n\t\tassert(0\
    \ <= l && l <= r && r <= n);\n\t\tif (l == r) return identity_elem();\n\t\tl +=\
    \ sz, r += sz;\n\t\tfor (usize i = log; i >= 1; --i) {\n\t\t\tif (((l >> i) <<\
    \ i) != l) pushdown(l >> i);\n\t\t\tif (((r >> i) << i) != r) pushdown((r - 1)\
    \ >> i);\n\t\t}\n\t\tS resl = identity_elem(), resr = identity_elem();\n\t\tfor\
    \ (; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) resl = operation(resl, dat[l++]);\n\
    \t\t\tif (r & 1) resr = operation(dat[--r], resr);\n\t\t}\n\t\treturn operation(resl,\
    \ resr);\n\t}\n\n\tS all_fold() const { return dat[1]; }\n\n\ttemplate <auto g>\n\
    \tusize max_right(usize l) {\n\t\treturn max_right(l, [](const S &x) -> bool {\
    \ return g(x); });\n\t}\n\n\ttemplate <typename G>\n\tusize max_right(usize l,\
    \ const G &g) {\n\t\tassert(0 <= l && l <= n);\n\t\tassert(g(identity_elem()));\n\
    \t\tif (l == n) return n;\n\t\tl += sz;\n\t\tfor (usize i = log; i >= 1; --i)\
    \ pushdown(l >> i);\n\t\tS prod = identity_elem();\n\t\tdo {\n\t\t\twhile (!(l\
    \ & 1)) l >>= 1;\n\t\t\tif (!g(operation(prod, dat[l]))) {\n\t\t\t\twhile (l <\
    \ sz) {\n\t\t\t\t\tpushdown(l);\n\t\t\t\t\tl <<= 1;\n\t\t\t\t\tif (g(operation(prod,\
    \ dat[l]))) prod = op(prod, dat[l++]);\n\t\t\t\t}\n\t\t\t\treturn l - sz;\n\t\t\
    \t}\n\t\t\tprod = op(prod, dat[l++]);\n\t\t} while ((l & -l) != l);\n\t\treturn\
    \ n;\n\t}\n\n\ttemplate <auto g>\n\tusize min_left(usize r) {\n\t\treturn min_left(r,\
    \ [](const S &x) -> bool { return g(x); });\n\t}\n\n\ttemplate <typename G>\n\t\
    usize min_left(usize r, const G& g) {\n\t\tassert(0 <= r && r <= n);\n\t\tassert(g(identity_elem()));\n\
    \t\tif (r == 0) return 0;\n\t\tr += sz;\n\t\tfor (usize i = log; i >= 1; --i)\
    \ pushdown((r - 1) >> i);\n\t\tS prod = identity_elem();\n\t\tdo {\n\t\t\t--r;\n\
    \t\t\twhile (r > 1 && (r & 1)) r >>= 1;\n\t\t\tif (!g(operation(dat[r], prod)))\
    \ {\n\t\t\t\twhile (r < sz) {\n\t\t\t\t\tpushdown(r);\n\t\t\t\t\tr = r * 2 + 1;\n\
    \t\t\t\t\tif (g(operation(dat[r], prod))) prod = operation(dat[r--], prod);\n\t\
    \t\t\t}\n\t\t\t\treturn r + 1 - sz;\n\t\t\t}\n\t\t\tprod = operation(dat[r], prod);\n\
    \t\t} while ((r & -r) != r);\n\t\treturn 0;\n\t}\n};\n};\n#line 5 \"verify/ds/lc-Range-Affine-Range-sum.test.cpp\"\
    \n\nusing mint = cpstd::Modint998244353;\nusing S = std::pair<mint, mint>;\nS\
    \ op(S a, S b) { return {a.first + b.first, a.second + b.second}; }\nS e() { return\
    \ {0, 0}; }\nS mp(S f, S x) { return {f.first * x.first + x.second * f.second,\
    \ x.second}; }\nS comp(S g, S f) { return {g.first * f.first, g.first * f.second\
    \ + g.second}; }\nS id() { return {1, 0}; }\n\nint main() {\n\ti32 N, Q;\n\tcpstd::input(N,\
    \ Q);\n\tstd::vector<S> A(N);\n\tfor (auto &a : A) cpstd::input(a.first), a.second\
    \ = 1;\n\tcpstd::LazySegtree<S, op, e, S, mp, comp, id> sg(A);\n\twhile (Q--)\
    \ {\n\t\ti32 t, l, r;\n\t\tcpstd::input(t, l, r);\n\t\tif (t == 0) {\n\t\t\ti32\
    \ b, c;\n\t\t\tcpstd::input(b, c);\n\t\t\tsg.apply(l, r, {b, c});\n\t\t}\n\t\t\
    else cpstd::println(sg.fold(l, r).first);\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"cpstl/other/Template.hpp\"\n#include \"cpstl/ds/LazySegtree.hpp\"\
    \n\nusing mint = cpstd::Modint998244353;\nusing S = std::pair<mint, mint>;\nS\
    \ op(S a, S b) { return {a.first + b.first, a.second + b.second}; }\nS e() { return\
    \ {0, 0}; }\nS mp(S f, S x) { return {f.first * x.first + x.second * f.second,\
    \ x.second}; }\nS comp(S g, S f) { return {g.first * f.first, g.first * f.second\
    \ + g.second}; }\nS id() { return {1, 0}; }\n\nint main() {\n\ti32 N, Q;\n\tcpstd::input(N,\
    \ Q);\n\tstd::vector<S> A(N);\n\tfor (auto &a : A) cpstd::input(a.first), a.second\
    \ = 1;\n\tcpstd::LazySegtree<S, op, e, S, mp, comp, id> sg(A);\n\twhile (Q--)\
    \ {\n\t\ti32 t, l, r;\n\t\tcpstd::input(t, l, r);\n\t\tif (t == 0) {\n\t\t\ti32\
    \ b, c;\n\t\t\tcpstd::input(b, c);\n\t\t\tsg.apply(l, r, {b, c});\n\t\t}\n\t\t\
    else cpstd::println(sg.fold(l, r).first);\n\t}\n\treturn 0;\n}"
  dependsOn:
  - cpstl/other/Template.hpp
  - cpstl/math/StaticModint.hpp
  - cpstl/other/Fastio.hpp
  - cpstl/ds/LazySegtree.hpp
  isVerificationFile: true
  path: verify/ds/lc-Range-Affine-Range-sum.test.cpp
  requiredBy: []
  timestamp: '2025-11-01 23:22:22+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/ds/lc-Range-Affine-Range-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/ds/lc-Range-Affine-Range-sum.test.cpp
- /verify/verify/ds/lc-Range-Affine-Range-sum.test.cpp.html
title: verify/ds/lc-Range-Affine-Range-sum.test.cpp
---
