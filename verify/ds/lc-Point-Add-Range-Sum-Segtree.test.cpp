#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "cpstl/other/Template.hpp"
#include "cpstl/ds/Segtree.hpp"

u64 op(u64 a, u64 b) { return a + b; }
u64 e() { return 0; }

int main() {
	i32 N, Q;
	cpstd::input(N, Q);
	std::vector<u64> A(N);
	cpstd::input(A);
	cpstd::Segtree<u64, op, e> sg(A);
	i32 t;
	while (Q--) {
		cpstd::input(t);
		if (t == 0) {
			i32 p;
			u64 x;
			cpstd::input(p, x);
			sg.add(p, x);
		}
		else {
			i32 l, r;
			cpstd::input(l, r);
			cpstd::println(sg.fold(l, r));
		}
	}
	return 0;
}
