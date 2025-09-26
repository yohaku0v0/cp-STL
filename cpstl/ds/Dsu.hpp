#pragma once
#include "cpstl/other/Template.hpp"

namespace cpstd {

template <
	typename S,
	auto op,
	auto e
>
class Dsu {
	private:
	int _n;
	std::vector<std::pair<int, S>> tree;

	int _leader(int x) {
		return tree[x].first < 0 ? x : tree[x].first = _leader(tree[x].first);
	}

	public:
	Dsu() {}
	explicit Dsu(int n) : _n(n), tree(n, {-1, e()}) {}
	Dsu(const std::vector<S> &v) : _n(int(v.size())) {
		tree.resize(_n);
		for (int i = 0; i < _n; ++i) tree[i] = {-1, v[i]};
	}

	int leader(int x) {
		assert(0 <= x && x < _n);
		return _leader(x);
	}

	bool merge(int a, int b) {
		assert(0 <= a && a < _n);
		assert(0 <= b && b < _n);
		a = _leader(a), b = _leader(b);
		if (a == b) return false;
		if (tree[a].first > tree[b].first) std::swap(a, b);
		tree[a].first += tree[b].first;
		tree[a].second = op(tree[a].second, tree[b].second);
		tree[b].first = a;
		return true;
	}

	bool same(int a, int b) {
		assert(0 <= a && a < _n);
		assert(0 <= b && b < _n);
		return _leader(a) == _leader(b);
	}

	int size(int x) {
		assert(0 <= x && x < _n);
		return -tree[_leader(x)].first;
	}

	const S fold(int x) {
		assert(0 <= x && x < _n);
		return tree[_leader(x)].first;
	}

	std::vector<std::vector<int>> groups() {
		std::vector<std::vector<int>> mem, res;
		for (int i = 0; i < _n; ++i) mem[_leader(i)].push_back(i);
		for (int i = 0; i < _n; ++i) {
			if (!mem[i].empty()) res.emplace_back(mem[i]);
		}
		return res;
	}
};
};
