#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "cpstl/other/Template.hpp"
#include "cpstl/ds/Segtree.hpp"

long long op(long long a, long long b) { return a + b; }
long long e() { return 0; }

int main() {
	int N, Q;
	cpstd::input(N, Q);
	std::vector<long long> A(N);
	cpstd::input(A);
	cpstd::Segtree<long long, op, e> sg(A);
	int t;
	while (Q--) {
		cpstd::input(t);
		if (t == 0) {
			int p;
			long long x;
			cpstd::input(p, x);
			sg.add(p, x);
		}
		else {
			int l, r;
			cpstd::input(l, r);
			cpstd::println(sg.fold(l, r));
		}
	}
	return 0;
}
