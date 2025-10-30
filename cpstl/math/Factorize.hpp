#pragma once
#include "cpstl/other/Template.hpp"
#include "cpstl/math/MillerRabin.hpp"

namespace cpstd {

std::vector<std::pair<u64, usize>> Factorize(u64 n) {
	if (n <= 1) return {};
	if (cpstd::MillerRabin(n)) return {{n, 1}};
	u64 X = n;
	std::vector<u64> p;
	for (u64 i = 2; i < 100; i += 1 + (i & 1)) {
		if (n % i) continue;
		p.push_back(i);
		while (!(n % i)) n /= i;
	}
	u64 r = 1;
	u128 n2 = 1;
	auto update = [&]() {
		r = n;
		for (usize i = 0; i < 6; ++i) r *= 2 - r * n;
		n2 = -(u128)n % n;
	};
	auto reduction = [&](u128 t) noexcept -> u64 {
		u64 s = ((u128)n * ((u64)t * r)) >> 64, t2 = t >> 64;
		return t2 - s + (t2 < s ? n : 0);
	};
	auto mul = [&](u64 a, u64 b) noexcept -> u64 {
		return reduction((u128)reduction((u128)a * n2) * b);
	};
	static u64 v = 7001;
	p.push_back(n);
	for (usize pi = p.size() - 1; pi < p.size(); ++pi) {
		while (p[pi] != 1 && !cpstd::MillerRabin(p[pi])) {
			n = p[pi], update();
			while (p[pi] == n) {
				v ^= v << 13, v ^= v >> 7, v ^= v << 17;
				u64 c = reduction(v);
				if (!c) continue;
				auto f = [&](u64 a) noexcept -> u64 {
					return reduction((u128)a * a + c);
				};
				u64 a = 0, b = f(a), buf = 1, sz = 1, nxt = 10;
				while (true) {
					while (nxt != sz && a != b) {
						buf = mul(buf, a > b ? a - b : b - a);
						++sz;
						a = f(a), b = f(f(b));
					}
					u64 g = Binarygcd(buf, n);
					if (g != 1) {
						while (!(p[pi] % g)) p[pi] /= g;
						p.push_back(g);
						break;
					}
					if (a == b) break;
					nxt = sz * 3 >> 1;
				}
			}
		}
	}
	std::vector<std::pair<u64, usize>> res;
	for (u64 q : p) {
		if (q == 1) continue;
		usize e = 0;
		while (!(X % q)) ++e, X /= q;
		if (e) res.emplace_back(q, e);
	}
	std::sort(res.begin(), res.end());
	return res;
}
};