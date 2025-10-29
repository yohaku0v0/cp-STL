#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "cpstl/other/Template.hpp"
#include "cpstl/ds/Dsu.hpp"

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
