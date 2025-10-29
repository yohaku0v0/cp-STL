#pragma once
#include "cpstl/other/Template.hpp"

namespace cpstd {

template <
	typename S,
	auto operation,
	S identity_elem
>
class Dsu {
	public:
	using value_type = S;

	private:
	i32 n;
	std::vector<std::pair<i32, S>> tree;

	i32 _leader(i32 x) {
		return tree[x].first < 0 ? x : tree[x].first = _leader(tree[x].first);
	}

	public:
	Dsu() {}

	explicit Dsu(i32 N) : n(N), tree(N, {-1, identity_elem}) {}
	
	explicit Dsu(const std::vector<S> &v) : n((i32)v.size()) {
		tree.resize(n);
		for (i32 i = 0; i < n; ++i) tree[i] = {-1, v[i]};
	}

	i32 leader(i32 x) {
		assert(0 <= x && x < n);
		return _leader(x);
	}

	bool merge(i32 a, i32 b) {
		assert(0 <= a && a < n);
		assert(0 <= b && b < n);
		a = _leader(a), b = _leader(b);
		if (a == b) return false;
		if (tree[a].first > tree[b].first) std::swap(a, b);
		tree[a].first += tree[b].first;
		tree[a].second = operation(tree[a].second, tree[b].second);
		tree[b].first = a;
		return true;
	}

	bool same(i32 a, i32 b) {
		assert(0 <= a && a < n);
		assert(0 <= b && b < n);
		return _leader(a) == _leader(b);
	}

	i32 size(i32 x) {
		assert(0 <= x && x < n);
		return -tree[_leader(x)].first;
	}

	S fold(i32 x) {
		assert(0 <= x && x < n);
		return tree[_leader(x)].first;
	}

	std::vector<std::vector<i32>> groups() {
		std::vector<std::vector<i32>> mem, res;
		for (i32 i = 0; i < n; ++i) mem[_leader(i)].push_back(i);
		for (i32 i = 0; i < n; ++i) {
			if (!mem[i].empty()) res.emplace_back(mem[i]);
		}
		return res;
	}
};
};
