#pragma once
#include <bits/stdc++.h>
#include "cpstl/math/StaticModint.hpp"
#include "cpstl/other/Fastio.hpp"

using i32 = std::int32_t;
using i64 = std::int64_t;
using i128 = __int128_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using u128 = unsigned __int128_t;
using usize = std::size_t;

constexpr i64 SafeMod(i64 x, u64 m) {
	x %= m;
	if (x < 0) x += m;
	return x;
}

constexpr u64 ModPow(i64 x, u64 n, u64 m) {
	if (m == 1) return 0;
	u64 res = 1, a = SafeMod(x, m);
	while (n) {
		if (n & 1) res = res * a % m;
		a = a * a % m;
		n >>= 1;
	}
	return res;
}

constexpr u128 ModPow_u128(i128 x, u128 n, u128 m) {
	if (m == 1) return 0;
	u128 res = 1, a = (x < 0 ? x % m + m : x % m);
	while (n) {
		if (n & 1) res = res * a % m;
		a = a * a % m;
		n >>= 1;
	}
	return res;
}

constexpr u64 Binarygcd(u64 a, u64 b) {
	if (!a || !b) return a | b;
	const i32 n = __builtin_ctzll(a | b);
	a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);
	while (a != b) {
		if (a > b) a -= b, b >>= __builtin_ctzll(b);
		else b -= a, a >>= __builtin_ctzll(a);
	}
	return a << n;
}

void YN(bool flag) {
	cpstd::println((flag ? "Yes" : "No"));
}