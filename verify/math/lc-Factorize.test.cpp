#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "cpstl/other/Template.hpp"
#include "cpstl/math/Factorize.hpp"

int main() {
	i32 Q;
	cpstd::input(Q);
	while (Q--) {
		u64 N;
		cpstd::input(N);
		auto f = cpstd::Factorize(N);
		usize k = 0;
		for (auto [p, e] : f) k += e;
		cpstd::print_ns(k, ' ');
		for (auto [p, e] : f) {
			for (usize i = 0; i < e; ++i) cpstd::print_ns(' ', p);
		}
		cpstd::println();
	}
	return 0;
}