#pragma once
#include "cpstl/other/Template.hpp"

namespace cpstd {

template <
	typename S,
	auto operation,
	auto identity_elem,
	typename F,
	auto mapping,
	auto composition,
	auto identity_map
>
class LazySegtree {
	private:
	std::vector<S> dat;
	std::vector<F> lazy;
	usize n, sz, log;

	void propagate(usize idx, const F &f) {
		dat[idx] = mapping(f, dat[idx]);
		if (idx < sz) lazy[idx] = composition(f, lazy[idx]);
	}

	void pushdown(usize idx) {
		if (lazy[idx] == identity_map()) return;
		propagate(idx * 2, lazy[idx]);
		propagate(idx * 2 + 1, lazy[idx]);
		lazy[idx] = identity_map();
	}

	void merge(usize idx) { dat[idx] = operation(dat[idx * 2], dat[idx * 2 + 1]); }

	void pushup(usize idx) {
		while (idx > 1) {
			idx >>= 1;
			merge(idx);
		}
	}

	public:
	LazySegtree() {}

	explicit LazySegtree(usize N) : LazySegtree(std::vector<S>(N, identity_elem())) {}

	LazySegtree(usize N, const S &x) : LazySegtree(std::vector<S>(N, x)) {}

	explicit LazySegtree(const std::vector<S> &v) : n(v.size()) {
		sz = std::bit_ceil(n);
		log = std::bit_width(sz - 1);
		dat.assign(sz * 2, identity_elem());
		lazy.assign(sz * 2, identity_map());
		for (usize i = 0; i < n; ++i) dat[i + sz] = v[i];
		for (usize i = sz - 1; i >= 1; --i) dat[i] = operation(dat[i * 2], dat[i * 2 + 1]);
	}

	void set(usize idx, const S &x) {
		assert(0 <= idx && idx < n);
		idx += sz;
		for (usize i = log; i >= 1; --i) pushdown(idx >> i);
		dat[idx] = x;
		pushup(idx);
	}

	void add(usize idx, const S &x) {
		assert(0 <= idx && idx < n);
		idx += sz;
		for (usize i = log; i >= 1; --i) pushdown(idx >> i);
		dat[idx] += x;
		pushup(idx);
	}

	void apply(usize idx, const F &f) {
		assert(0 <= idx && idx < n);
		idx += sz;
		for (usize i = log; i >= 1; --i) pushdown(idx >> i);
		dat[idx] = mapping(f, dat[idx]);
		pushup(idx);
	}

	void apply(usize l, usize r, const F &f) {
		assert(0 <= l && l <= r && r <= n);
		if (l == r) return;
		l += sz, r += sz;
		for (usize i = log; i >= 1; --i) {
			if (((l >> i) << i) != l) pushdown(l >> i);
			if (((r >> i) << i) != r) pushdown((r - 1) >> i);
		}
		for (usize l2 = l, r2 = r; l2 < r2; l2 >>= 1, r2 >>= 1) {
			if (l2 & 1) propagate(l2++, f);
			if (r2 & 1) propagate(--r2, f);
		}
		for (usize i = 1; i <= log; ++i) {
			if (((l >> i) << i) != l) merge(l >> i);
			if (((r >> i) << i) != r) merge((r - 1) >> i);
		}
	}

	S get(usize idx) {
		assert(0 <= idx && idx < n);
		idx += sz;
		for (usize i = log; i >= 1; --i) pushdown(idx >> i);
		return dat[idx];
	}

	S operator[](usize idx) noexcept {
		idx += sz;
		for (usize i = log; i >= 1; --i) pushdown(idx >> i);
		return dat[idx];
	}

	S fold(usize l, usize r) {
		assert(0 <= l && l <= r && r <= n);
		if (l == r) return identity_elem();
		l += sz, r += sz;
		for (usize i = log; i >= 1; --i) {
			if (((l >> i) << i) != l) pushdown(l >> i);
			if (((r >> i) << i) != r) pushdown((r - 1) >> i);
		}
		S resl = identity_elem(), resr = identity_elem();
		for (; l < r; l >>= 1, r >>= 1) {
			if (l & 1) resl = operation(resl, dat[l++]);
			if (r & 1) resr = operation(dat[--r], resr);
		}
		return operation(resl, resr);
	}

	S all_fold() const { return dat[1]; }

	template <auto g>
	usize max_right(usize l) {
		return max_right(l, [](const S &x) -> bool { return g(x); });
	}

	template <typename G>
	usize max_right(usize l, const G &g) {
		assert(0 <= l && l <= n);
		assert(g(identity_elem()));
		if (l == n) return n;
		l += sz;
		for (usize i = log; i >= 1; --i) pushdown(l >> i);
		S prod = identity_elem();
		do {
			while (!(l & 1)) l >>= 1;
			if (!g(operation(prod, dat[l]))) {
				while (l < sz) {
					pushdown(l);
					l <<= 1;
					if (g(operation(prod, dat[l]))) prod = op(prod, dat[l++]);
				}
				return l - sz;
			}
			prod = op(prod, dat[l++]);
		} while ((l & -l) != l);
		return n;
	}

	template <auto g>
	usize min_left(usize r) {
		return min_left(r, [](const S &x) -> bool { return g(x); });
	}

	template <typename G>
	usize min_left(usize r, const G& g) {
		assert(0 <= r && r <= n);
		assert(g(identity_elem()));
		if (r == 0) return 0;
		r += sz;
		for (usize i = log; i >= 1; --i) pushdown((r - 1) >> i);
		S prod = identity_elem();
		do {
			--r;
			while (r > 1 && (r & 1)) r >>= 1;
			if (!g(operation(dat[r], prod))) {
				while (r < sz) {
					pushdown(r);
					r = r * 2 + 1;
					if (g(operation(dat[r], prod))) prod = operation(dat[r--], prod);
				}
				return r + 1 - sz;
			}
			prod = operation(dat[r], prod);
		} while ((r & -r) != r);
		return 0;
	}
};
};