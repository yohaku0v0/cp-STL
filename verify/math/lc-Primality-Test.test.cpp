#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include "cpstl/other/Template.hpp"
#include "cpstl/math/MillerRabin.hpp"

int main() {
	i32 Q;
	cpstd::input(Q);
	while (Q--) {
		u64 N;
		cpstd::input(N);
		YN(cpstd::MillerRabin(N));
	}
}