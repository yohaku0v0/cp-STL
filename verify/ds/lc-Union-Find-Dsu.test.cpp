#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "cpstl/other/Template.hpp"
#include "cpstl/ds/Dsu.hpp"

int op(int a, int b) { return a; }
int e() { return 0; }

int main() {
	int N, Q;
	cpstd::input(N, Q);
	cpstd::Dsu<int, op, e> dsu(N);
	int t, u, v;
	while (Q--) {
		cpstd::input(t, u, v);
		if (t == 0) dsu.merge(u, v);
		else cpstd::println((dsu.same(u, v) ? "1" : "0"));
	}
}
