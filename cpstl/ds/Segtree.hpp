#pragma once
#include "cpstl/other/Template.hpp"

namespace cpstd {

template <
	typename S,
	auto op,
	auto e
>
class Segtree {
	private:
	std::vector<S> dat;
	int N, sz;

	public:
	Segtree() {}
	explicit Segtree(int n) : Segtree(std::vector<S>(n, e())) {}
	explicit Segtree(int n, const S &init) : Segtree(std::vector<S>(n, init)) {}
	explicit Segtree(const std::vector<S> &v) : N((int)v.size()) {
		sz = 1;
		while (sz < N) sz <<= 1;
		dat.assign(sz << 1, e());
		for (int i = 0; i < N; ++i) dat[i + sz] = v[i];
		for (int i = sz - 1; i >= 1; --i) dat[i] = op(dat[i << 1], dat[i << 1 | 1]);
	}
	template <class Inputit>
	Segtree(Inputit first, Inputit last) : Segtree(std::vector<S>(first, last)) {}

	void set(int pos, const S &x) {
		assert(0 <= pos && pos < N);
		pos += sz;
		dat[pos] = x;
		while (pos > 1) {
			pos >>= 1;
			dat[pos] = op(dat[pos << 1], dat[pos << 1 | 1]);
		}
	}

	void add(int pos, const S &x) {
		assert(0 <= pos && pos < N);
		pos += sz;
		dat[pos] += x;
		while (pos > 1) {
			pos >>= 1;
			dat[pos] = op(dat[pos << 1], dat[pos << 1 | 1]);
		}
	}

	template <
		typename F,
		auto mapping
	>
	void set(int pos, const F &f) {
		assert(0 <= pos && pos < N);
		pos += sz;
		dat[pos] = mapping(f, dat[pos]);
		while (pos > 1) {
			pos >>= 1;
			dat[pos] = op(dat[pos << 1], dat[pos << 1 | 1]);
		}
	}

	const S& get(int pos) const {
		assert(0 <= pos && pos < N);
		return dat[pos + sz];
	}

	const S& operator[](int pos) const noexcept { return dat[pos + sz]; }

	S fold(int l, int r) const {
		assert(0 <= l && l <= r && r <= N);
		if (l == r) return e();
		S resl = e(), resr = e();
		for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
			if (l & 1) resl = op(resl, dat[l++]);
			if (r & 1) resr = op(dat[--r], resr);
		}
		return op(resl, resr);
	}

	S all_fold() const { return dat[1]; }

	template <typename F>
	int max_right(int l, const F& f) const {
		assert(0 <= l && l <= N);
		assert(f(e()));
		if (l == N) return N;
		l += sz;
		S s = e();
		do {
			while (!(l & 1)) l >>= 1;
			if (!f(op(s, dat[l]))) {
				while (l < sz) {
					l <<= 1;
					if (f(op(s, dat[l]))) s = op(s, dat[l++]);
				}
				return l - sz;
			}
			s = op(s, dat[l++]);
		} while ((l & -l) != l);
		return N;
	}

	template <typename F>
	int min_left(int r, const F &f) const {
		assert(0 <= r && r <= N);
		assert(f(e()));
		if (r == 0) return 0;
		r += sz;
		S s = e();
		do {
			--r;
			while (r > 1 && (r & 1)) r >>= 1;
			if (!f(op(dat[r], s))) {
				while (r < sz) {
					r = r << 1 | 1;
					if (f(op(dat[r], s))) s = op(dat[r--], s);
				}
				return r + 1 - sz;
			}
			s = op(dat[r], s);
		} while ((r & -r) != r);
		return 0;
	}
};
};
