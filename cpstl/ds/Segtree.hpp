#pragma once
#include "cpstl/other/Template.hpp"

namespace cpstd {

template <
	typename S,
	auto operation,
	S identity_elem
>
class Segtree {
	public:
	using value_type = S;

	private:
	std::vector<S> dat;
	usize n, sz;

	void pushup(usize idx) {
		while (idx > 1) {
			idx >>= 1;
			dat[idx] = operation(dat[idx * 2], dat[idx * 2 + 1]);
		}
	}

	public:
	Segtree() {}
	
	explicit Segtree(u32 N) : Segtree(std::vector<S>(N, identity_elem)) {}

	Segtree(u32 N, const S &x) : Segtree(std::vector<S>(N, x)) {}

	explicit Segtree(const std::vector<S> &v) : n((u32)v.size()) {
		sz = 1;
		while (sz < n) sz <<= 1;
		dat.assign(sz * 2, identity_elem);
		for (usize i = 0; i < n; ++i) dat[sz + i] = v[i];
		for (usize i = sz - 1; i >= 1; --i) dat[i] = operation(dat[i * 2], dat[i * 2 + 1]);
	}

	void set(usize idx, const S &x) {
		assert(idx < n);
		idx += sz;
		dat[idx] = x;
		pushup(idx);
	}

	void add(usize idx, const S &x) {
		assert(idx < n);
		idx += sz;
		dat[idx] += x;
		pushup(idx);
	}

	S fold(usize l, usize r) const {
		assert(l <= r && r <= n);
		S resl = identity_elem, resr = identity_elem;
		for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
			if (l & 1) resl = operation(resl, dat[l++]);
			if (r & 1) resr = operation(dat[--r], resr);
		}
		return operation(resl, resr);
	}

	S all_fold() const noexcept { return dat[1]; }

	S get(usize idx) const {
		assert(0 <= idx && idx < n);
		return dat[idx + sz];
	}

	S operator[](usize idx) const noexcept { return dat[idx + sz]; }

	template <typename F>
	usize max_right(usize l, const F &f) const {
		assert(0 <= l && l <= n);
		assert(f(identity_elem));
		if (l == n) return n;
		l += sz;
		S prod = identity_elem;
		do {
			while (!(l & 1)) l >>= 1;
			if (!f(operation(prod, dat[l]))) {
				while (l < sz) {
					l <<= 1;
					if (f(op(prod, dat[l]))) prod = operation(prod, dat[l++]);
				}
				return l - sz;
			}
			prod = operation(prod, dat[l++]);
		} while ((l & -l) != l);
		return n;
	}

	template <typename F>
	usize min_left(usize r, const F &f) const {
		assert(0 <= r && r <= n);
		assert(f(identity_elem));
		if (r == 0) return 0;
		r += sz;
		S prod = identity_elem;
		do {
			--r;
			while (r > 1 && (r & 1)) r >>= 1;
			if (!f(operation(dat[r], prod))) {
				while (r < sz) {
					r = r * 2 + 1;
					if (f(op(dat[r], prod))) prod = operation(dat[r--], prod);
				}
				return r + 1 - sz;
			}
			prod = operation(dat[r], prod);
		} while ((r & -r) != r);
		return 0;
	}
};
};
