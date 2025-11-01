#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"

#include "cpstl/other/Template.hpp"
#include "cpstl/ds/RbstSet.hpp"

int main() {
	i32 N, Q;
	cpstd::input(N, Q);
	cpstd::RbstSet<i32> S;
	i32 a;
	for (usize i = 0; i < N; ++i) cpstd::input(a), S.insert(a);
	while (Q--) {
		i32 t, x;
		cpstd::input(t, x);
		if (t == 0) S.insert(x);
		else if (t == 1) S.erase(x);
		else if (t == 2) cpstd::println((x > S.size() ? -1 : S[x - 1]));
		else if (t == 3) cpstd::println(S.order_of_key(S.upper_bound(x)));
		else if (t == 4) cpstd::println((S.empty() || x <= *S.begin() ? -1 : *--S.upper_bound(x)));
		else if (t == 5) cpstd::println((S.lower_bound(x) != S.end() ? *S.lower_bound(x) : -1));
	}
}