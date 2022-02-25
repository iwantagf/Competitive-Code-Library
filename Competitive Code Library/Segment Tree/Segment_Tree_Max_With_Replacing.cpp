#include<bits/stdc++.h>
#define maxn (int) 1e5 + 7
using namespace std;
int n, a[maxn], m;
struct Node {
	int left, right;
	int l, r;
	int gmax, lazy;
	bool islazy;
	Node(int lo, int hi): l(lo), r(hi) {
		left = right = -1;
		gmax = -INT_MAX;
		lazy = 0;
		islazy = false;
	}
};

struct STMAX {
	vector<Node> T;

	//Build the tree
	int Build(int lo, int hi) {
		Node A = Node(lo, hi);
		T.push_back(A);
		int u = T.size() - 1;
		if (lo == hi) {
			T[u].gmax = a[lo];
			return u;
		}

		int mid = (lo + hi)/2;

		T[u].left = Build(lo, mid);
		T[u].right = Build(mid + 1, hi);

		T[u].gmax = max(T[T[u].left].gmax, T[T[u].right].gmax);

		return u;
	}


	void down(int r) {
		if (T[r].islazy) {
			T[T[r].left].lazy = T[r].lazy;
			T[T[r].right].lazy = T[r].lazy;
			T[T[r].left].islazy = T[T[r].right].islazy = true;
			T[r].islazy = false;
		}
	}


	void up(int r) {
		if (T[T[r].left].islazy && T[T[r].right].islazy) { 
			T[r].gmax = max(T[T[r].left].lazy, T[T[r].right].lazy);
			return;
		}
		if (T[T[r].left].islazy == false && T[T[r].right].islazy) {
			T[r].gmax = max(T[T[r].left].gmax, T[T[r].right].lazy);
			return;
		}
		if (T[T[r].left].islazy && T[T[r].right].islazy == false) {
			T[r].gmax = max(T[T[r].left].lazy, T[T[r].right].gmax);
			return;
		}
		if (T[T[r].left].islazy == false && T[T[r].right].islazy == false) {
			T[r].gmax = max(T[T[r].left].gmax, T[T[r].right].gmax);
			return;
		}
	}

	//Update values with lazy progpagation
	void Upd(int r, int u, int v, int val) {
		int lo = T[r].l, hi = T[r].r;

		if (v < lo || u > hi) return;

		if (u <= lo && hi <= v) {
			T[r].gmax = val;
			T[r].lazy = val;
			T[r].islazy = true;
			return;
		}

		
		down(r);

		Upd(T[r].left, u, v, val);
		Upd(T[r].right, u, v, val);

		up(r);
	}


	//Get max from a[u], ..., a[v];
	int Get(int r, int u, int v) {
		int lo = T[r].l, hi = T[r].r;

		if (v < lo || u > hi) return -INT_MAX;

		if (u <= lo && hi <= v) {
			if (T[r].islazy == false) return T[r].gmax;
			else return T[r].lazy;
		}

		down(r);

		int TL = Get(T[r].left, u, v);
		int TR = Get(T[r].right, u, v);
		
		up(r);

		return max(TL, TR);
	}
};

STMAX Tree;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i) cin >> a[i];
	int loai;
	int root = Tree.Build(1, n);
	
	cin >> m;


	while (m--) {
		cin >> loai;
		if (loai == 1) {
			int u, v, delta;
			cin >> u >> v >> delta;
			Tree.Upd(root, u, v, delta);
		}
		else if (loai == 2) {
			int u, v;
			cin >> u >> v;
			cout << Tree.Get(root, u, v) << '\n';
		}
	}
}