#include<bits/stdc++.h>
#define fi first
#define sc second
using namespace std;
const int maxn = 2e6 + 9;

int q, tmp[maxn], r = 0, total = 0;

pair<char, int> event[maxn];

struct node {
	int left, right;
	int l, r;
	int sum;

	node(int lo, int hi): l(lo), r(hi) {
		left = right = -1;
		sum = 0;
	}
};

struct ordset {
	vector<node> T;

	int Build(int lo, int hi) {
		node A = node(lo, hi);
		T.push_back(A);

		int r = T.size() - 1;

		if (lo == hi) return r;

		int mid = (lo + hi)/2;

		T[r].left = Build(lo, mid);
		T[r].right = Build(mid + 1, hi);

		return r;
	}

	void Modify(int r, int u, int val) {
		int lo = T[r].l, hi = T[r].r;

		if (lo == hi) {
			T[r].sum = val;
			return;
		}

		int mid = (lo + hi)/2;

		if (u <= mid) Modify(T[r].left, u, val);
		else Modify(T[r].right, u, val);

		T[r].sum = T[T[r].left].sum + T[T[r].right].sum;
	}

	int rankk(int r, int k) {
		int lo = T[r].l, hi = T[r].r;

		if (lo == hi) return lo;
		int m = T[T[r].left].sum;

		if (k <= m) return rankk(T[r].left, k);
		else return rankk(T[r].right, k - m);
	}

	int Get(int r, int u, int v) {
		int lo = T[r].l, hi = T[r].r;
		if (u > hi || v < lo) return 0;

		if (u <= lo && hi <= v) return T[r].sum;

		int TL = Get(T[r].left, u, v);
		int TR = Get(T[r].right, u, v);

		return TL + TR;
	}
};

ordset Tree;

int main() {
	int root = Tree.Build(1, maxn);

}