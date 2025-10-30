#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "cpstl/other/Template.hpp"
#include "cpstl/ds/LazySegtree.hpp"

using mint = cpstd::Modint998244353;
using S = std::pair<mint, mint>;
S op(S a, S b) { return {a.first + b.first, a.second + b.second}; }
S e() { return {0, 0}; }
S mp(S f, S x) { return {f.first * x.first + x.second * f.second, x.second}; }
S comp(S g, S f) { return {g.first * f.first, g.first * f.second + g.second}; }
S id() { return {1, 0}; }

int main() {
	i32 N, Q;
	cpstd::input(N, Q);
	std::vector<S> A(N);
	for (auto &a : A) cpstd::input(a.first), a.second = 1;
	cpstd::LazySegtree<S, op, e, S, mp, comp, id> sg(A);
	while (Q--) {
		i32 t, l, r;
		cpstd::input(t, l, r);
		if (t == 0) {
			i32 b, c;
			cpstd::input(b, c);
			sg.apply(l, r, {b, c});
		}
		else cpstd::println(sg.fold(l, r).first);
	}
	return 0;
}