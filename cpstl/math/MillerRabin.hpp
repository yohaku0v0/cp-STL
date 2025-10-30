#pragma once
#include "cpstl/other/Template.hpp"

namespace cpstd {

constexpr bool MillerRabin(u64 n) {
	if (n <= 1) return false;
	if (!(n & 1)) return n == 2;
	u64 d = n - 1;
	i32 s = 0, q = 63;
	while (!(d & 1)) ++ s, d >>= 1;
	while (!(d >> q)) --q;
	u64 r = n;
	for (usize i = 0; i < 6; ++i) r *= 2 - r * n;
	u128 n2 = -(u128)n % n;
	auto reduction = [&](u128 t) noexcept -> u64 {
		t = (t + (u128)((u64)t * -r) * n) >> 64;
		return t < n ? t : t - n;
	};
	u64 one = reduction(n2);
	for (u64 base : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
		if (!(base % n)) continue;
		u64 a = base = reduction(base % n * n2);
		for (i32 e = q - 1; e >= 0; --e) {
			a = reduction((u128)a * a);
			if (d >> e & 1) a = reduction((u128)a * base);
		}
		if (a == one) continue;
		for (usize t = 1; (t < s && a != n - one); ++t) a = reduction((u128)a * a);
		if (a != n - one) return false;
	}
	return true;
}
};