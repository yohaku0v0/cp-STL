#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb_128bit"

#include "cpstl/other/Template.hpp"

int main() {
	int T;
	cpstd::input(T);
	i128 A, B;
	while (T--) {
		cpstd::input(A, B);
		cpstd::println(A + B);
	}
}
