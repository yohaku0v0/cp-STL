#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <bits/stdc++.h>

namespace cpstd {

template <uint32_t m>
struct StaticModint {
	private:
	using mint = StaticModint;
	uint32_t _v = 0;

	static constexpr bool is_prime = []() -> bool {
		if (m == 1) return false;
		if (m == 2 || m == 7 || m == 61) return true;
		if (!(m & 1)) return false;
		uint32_t d = m - 1;
		while (!(d & 1)) d >>= 1;
		for (uint32_t a : {2, 7, 61}) {
			uint32_t t = d;
			mint y = mint(a).pow(t);
			while (t != m - 1 && y != 1 && y != m - 1) {
				y *= y;
				t <<= 1;
			}
			if (y != m - 1 && !(t & 1)) return false;
		}
		return true;
	}();
	
	static constexpr std::pair<int32_t, int32_t> inv_gcd(int32_t a, int32_t b) {
		if (a == 0) return {b, 0};
		int32_t s = b, t = a, m0 = 0, m1 = 1;
		while (t) {
			const int32_t q = s / t;
			s -= t * q, std::swap(s, t);
			m0 -= m1 * q, std::swap(m0, m1);
		}
		if (m0 < 0) m0 += b / s;
		return {s, m0};
	}

	public:
	constexpr StaticModint() {}
	template <typename T>
	constexpr StaticModint(T v) {
		static_assert(std::is_integral_v<T>, "T is not integral type.");
		if constexpr (std::is_signed_v<T>) {
			int64_t x = int64_t(v % int64_t(m));
			if (x < 0) x += m;
			_v = uint32_t(x);
		}
		else _v = uint32_t(v % m);
	}

	static constexpr mint raw(uint32_t v) { mint a; a._v = v; return a; }

	static constexpr uint32_t mod() { return m; }

	constexpr uint32_t val() const { return _v; }

	constexpr mint& operator++() { return *this += 1; }

	constexpr mint operator++(int) { mint res = *this; ++*this; return res; }

	constexpr mint& operator--() { return *this -= 1; }

	constexpr mint operator--(int) { mint res = *this; --*this; return res; }

	constexpr mint& operator+=(mint rhs) {
		if (_v >= m - rhs._v) _v -= m;
		_v += rhs._v;
		return *this;
	}

	constexpr mint& operator-=(mint rhs) {
		if (_v < rhs._v) _v += m;
		_v -= rhs._v;
		return *this;
	}

	constexpr mint& operator*=(mint rhs) { return *this = *this * rhs; }

	constexpr mint& operator/=(mint rhs) { return *this *= rhs.inv(); }

	constexpr mint operator+() const { return *this; }

	constexpr mint operator-() const { return mint{} - *this; }

	constexpr mint pow(long long n) const {
		assert(0 <= n);
		if (n == 0) return 1;
		mint x = *this, r = 1;
		while (n > 0) {
			if (n & 1) r *= x;
			x *= x;
			n >>= 1;
			if (!n) return r;
		}
		return r;
	}

	constexpr mint inv() const {
		if constexpr (is_prime) {
			assert(_v);
			return pow(m - 2);
		}
		else {
			auto eg = inv_gcd(_v, m);
			assert(eg.first == 1);
			return eg.second;
		}
	}

	friend constexpr mint operator+(mint lhs, mint rhs) { return lhs += rhs; }

	friend constexpr mint operator-(mint lhs, mint rhs) { return lhs -= rhs; }

	friend constexpr mint operator*(mint lhs, mint rhs) { return uint64_t(lhs._v) * rhs._v; }
	
	friend constexpr mint operator/(mint lhs, mint rhs) { return lhs /= rhs; }

	friend constexpr bool operator==(mint lhs, mint rhs) { return lhs._v == rhs._v; }

	friend constexpr bool operator!=(mint lhs, mint rhs) { return lhs._v != rhs._v; }
};

using Modint998244353 = StaticModint<998244353>;

constexpr Modint998244353 operator""_M(unsigned long long x) { return x; }
};

namespace cpstd {

namespace Fastio {

static constexpr const uint32_t BUF_SIZE = 1 << 17;
char ibuf[BUF_SIZE], obuf[BUF_SIZE], out[100];
uint32_t pil = 0, pir = 0, por = 0;

struct Pre {
	char num[10000][4];

	constexpr Pre() : num() {
		for (int i = 0; i < 10000; ++i) {
			int n = i;
			for (int j = 3; j >= 0; --j) {
				num[i][j] = n % 10 | '0';
				n /= 10;
			}
		}
	}
} constexpr pre;

inline void load() {
	std::memcpy(ibuf, ibuf + pil, pir - pil);
	pir = pir - pil + std::fread(ibuf + pir - pil, 1, BUF_SIZE - pir + pil, stdin);
	pil = 0;
	if (pir < BUF_SIZE) ibuf[pir++] = '\n';
}

inline void flush() {
	fwrite(obuf, 1, por, stdout);
	por = 0;
}

void _input(char &dest) {
	do {
		if (pil + 1 > pir) load();
		dest = ibuf[pil++];
	} while (std::isspace(dest));
}

void _input(std::string &dest) {
	dest.clear();
	char c;
	do {
		if (pil + 1 > pir) load();
		c = ibuf[pil++];
	} while (std::isspace(c));
	do {
		dest += c;
		if (pil == pir) load();
		c = ibuf[pil++];
	} while (!std::isspace(c));
}

void _input(float &dest) {
	std::string s;
	_input(s);
	dest = std::stof(s);
}

void _input(double &dest) {
	std::string s;
	_input(s);
	dest = std::stod(s);
}

void _input(long double &dest) {
	std::string s;
	_input(s);
	dest = std::stold(s);
}

template <typename T>
void input_int(T &x) {
	if (pil + 100 > pir) load();
	char c;
	do {
		c = ibuf[pil++];
	} while (c < '-');
	bool minus = 0;
	if constexpr (std::is_signed<T>::value || std::is_same_v<T, __int128_t>) {
		if (c == '-') minus = 1, c = ibuf[pil++];
	}
	x = 0;
	while (c >= '0') x = x * 10 + (c & 15), c = ibuf[pil++];
	if constexpr (std::is_signed<T>::value || std::is_same_v<T, __int128_t>) {
		if (minus) x = -x;
	}
}

void _input(int &dest) { input_int(dest); }
void _input(unsigned int &dest) { input_int(dest); }
void _input(long long &dest) { input_int(dest); }
void _input(unsigned long long &dest) { input_int(dest); }
void _input(__int128 &dest) { input_int(dest); }
void _input(unsigned __int128 &dest) { input_int(dest); }

template <uint32_t m>
void _input(cpstd::StaticModint<m> &dest) { long long a; _input(a); dest = a; }

template <typename T, typename U>
void _input(std::pair<T, U> &dest) { _input(dest.first), _input(dest.second); }

template <std::size_t N = 0, typename T>
void input_tuple(T &t) {
	if constexpr (N < std::tuple_size<T>::value) {
		auto &x = std::get<N>(t);
		input(x);
		input_tuple<N + 1>(t);
	}
}

template <typename... T>
void _input(std::tuple<T...> &dest) { input_tuple(dest); }

template <std::size_t N = 0, typename T>
void _input(std::array<T, N> &dest) { for (auto &e : dest) _input(e); }

template <typename T>
void _input(std::vector<T> &dest) { for (auto &e : dest) _input(e); }

void input() {}

// 各引数に入力
template <typename H, typename... T>
void input(H &desth, T &... destt) { _input(desth), input(destt...); }

void _print(const char tg) {
	if (por == BUF_SIZE) flush();
	obuf[por++] = tg;
}

void _print(const std::string tg) { for (char c : tg) _print(c); }

void _print(const char *tg) {
	std::size_t len = std::strlen(tg);
	for (std::size_t i = 0; i < len; ++i) _print(tg[i]);
}

template <typename T>
void print_int(T x) {
	if (por > BUF_SIZE - 100) flush();
	if (x < 0) obuf[por++] = '-', x = -x;
	int outi;
	for (outi = 96; x >= 10000; outi -= 4) {
		std::memcpy(out + outi, pre.num[x % 10000], 4);
		x /= 10000;
	}
	if (x >= 1000) {
		std::memcpy(obuf + por, pre.num[x], 4);
		por += 4;
	}
	else if (x >= 100) {
		std::memcpy(obuf + por, pre.num[x] + 1, 3);
		por += 3;
	}
	else if (x >= 10) {
		int q = (x * 103) >> 10;
		obuf[por] = q | '0';
		obuf[por + 1] = (x - q * 10) | '0';
		por += 2;
	}
	else obuf[por++] = x | '0';
	std::memcpy(obuf + por, out + outi + 4, 96 - outi);
	por += 96 - outi;
}

template <typename T>
void print_real(T tg) {
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(15) << double(tg);
	std::string s = oss.str();
	_print(s);
}

void _print(int tg) { print_int(tg); }
void _print(unsigned int tg) { print_int(tg); }
void _print(long long tg) { print_int(tg); }
void _print(unsigned long long tg) { print_int(tg); }
void _print(__int128 tg) { print_int(tg); }
void _print(unsigned __int128 tg) { print_int(tg); }
void _print(float tg) { print_real(tg); }
void _print(double tg) { print_real(tg); }
void _print(long double tg) { print_real(tg); }

template <uint32_t m>
void _print(cpstd::StaticModint<m> tg) { print_int(tg.val()); }

template <typename T, typename U>
void _print(const std::pair<T, U> tg) {
	_print(tg.first);
	_print(' ');
	_print(tg.second);
}

template <std::size_t N = 0, typename T>
void print_tuple(const T tg) {
	if constexpr (N < std::tuple_size<T>::value) {
		if constexpr (N > 0) _print(' ');
		const auto x = std::get<N>(tg);
		_print(x);
		print_tuple<N + 1>(tg);
	}
}

template <typename... T>
void _print(std::tuple<T...> tg) { print_tuple(tg); }

template <typename T, std::size_t N>
void _print(const std::array<T, N> tg) {
	auto len = tg.size();
	for (std::size_t i = 0; i < len; ++i) {
		if (i) _print(' ');
		_print(tg[i]);
	}
}

template <typename T>
void _print(const std::vector<T> tg) {
	auto  len = tg.size();
	for (std::size_t i = 0; i < len; ++i) {
		if (i) _print(' ');
		_print(tg[i]);
	}
}

void print() {}

template <typename H, typename... T>
void print(H &&tgh, T &&... tgt) {
	_print(tgh);
	if constexpr (sizeof...(tgt)) {
		_print(' ');
		print(std::forward<T>(tgt)...);
	}
}

void println() { _print('\n'); }

template <typename H, typename... T>
void println(H &&tgh, T &&... tgt) {
	_print(tgh);
	if (sizeof...(tgt)) _print(' ');
	println(std::forward<T>(tgt)...);
}

void print_ns() {}

template <typename H, typename... T>
void print_ns(H &&tgh, T &&... tgt) {
	_print(tgh);
	print_ns(std::forward<T>(tgt)...);
}

void println_ns() { _print('\n'); }

template <typename H, typename... T>
void println_ns(H &&tgh, T &&... tgt) {
	_print(tgh);
	println_ns(std::forward<T>(tgt)...);
}

void __attribute__((destructor)) _d() { flush(); }

};

using Fastio::input;
using Fastio::print;
using Fastio::println;
using Fastio::print_ns;
using Fastio::println_ns;
using Fastio::flush;

};

using i32 = std::int32_t;
using i64 = std::int64_t;
using i128 = __int128_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using u128 = unsigned __int128_t;
using usize = std::size_t;

namespace cpstd {

template <
	typename S,
	auto operation,
	S identity_elem
>
class Dsu {
	public:
	using value_type = S;

	private:
	i32 n;
	std::vector<std::pair<i32, S>> tree;

	i32 _leader(i32 x) {
		return tree[x].first < 0 ? x : tree[x].first = _leader(tree[x].first);
	}

	public:
	Dsu() {}

	explicit Dsu(i32 N) : n(N), tree(N, {-1, identity_elem}) {}
	
	explicit Dsu(const std::vector<S> &v) : n((i32)v.size()) {
		tree.resize(n);
		for (i32 i = 0; i < n; ++i) tree[i] = {-1, v[i]};
	}

	i32 leader(i32 x) {
		assert(0 <= x && x < n);
		return _leader(x);
	}

	bool merge(i32 a, i32 b) {
		assert(0 <= a && a < n);
		assert(0 <= b && b < n);
		a = _leader(a), b = _leader(b);
		if (a == b) return false;
		if (tree[a].first > tree[b].first) std::swap(a, b);
		tree[a].first += tree[b].first;
		tree[a].second = operation(tree[a].second, tree[b].second);
		tree[b].first = a;
		return true;
	}

	bool same(i32 a, i32 b) {
		assert(0 <= a && a < n);
		assert(0 <= b && b < n);
		return _leader(a) == _leader(b);
	}

	i32 size(i32 x) {
		assert(0 <= x && x < n);
		return -tree[_leader(x)].first;
	}

	S fold(i32 x) {
		assert(0 <= x && x < n);
		return tree[_leader(x)].first;
	}

	std::vector<std::vector<i32>> groups() {
		std::vector<std::vector<i32>> mem, res;
		for (i32 i = 0; i < n; ++i) mem[_leader(i)].push_back(i);
		for (i32 i = 0; i < n; ++i) {
			if (!mem[i].empty()) res.emplace_back(mem[i]);
		}
		return res;
	}
};
};

i32 op(i32 a, i32 b) { return a; }

int main() {
	i32 N, Q;
	cpstd::input(N, Q);
	cpstd::Dsu<i32, op, 0> dsu(N);
	i32 t, u, v;
	while (Q--) {
		cpstd::input(t, u, v);
		if (t == 0) dsu.merge(u, v);
		else cpstd::println((dsu.same(u, v) ? "1" : "0"));
	}
}
