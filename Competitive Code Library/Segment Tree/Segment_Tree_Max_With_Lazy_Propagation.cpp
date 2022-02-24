#include<bits/stdc++.h>
#define maxn (int) 1e5 + 7
using namespace std;
int n, a[maxn], m;


struct STMAX {
	struct Node {
		int left, right;
		int l, r;
		long long gmax, lazy;
		Node(int lo, int hi): l(lo), r(hi) {
			left = right = -1;
			gmax = -INT_MAX;
			lazy = 0;
		}
	};

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
		long long t = T[r].lazy;
		
		T[T[r].left].lazy += t;
		T[T[r].left].gmax += t;
		
		T[T[r].right].lazy += t;
		T[T[r].right].gmax += t;
		
		T[r].lazy = 0;
	}

	//Update values with lazy progpagation
	void Upd(int r, int u, int v, int val) {
		int lo = T[r].l, hi = T[r].r;
		if (v < lo || u > hi) return;

		if (u <= lo && hi <= v) {
			T[r].gmax += val;
			T[r].lazy += val;
			return;
		}

		
		down(r);

		Upd(T[r].left, u, v, val);
		Upd(T[r].right, u, v, val);

		T[r].gmax = max(T[T[r].left].gmax, T[T[r].right].gmax);

	}


	//Get max from a[u], ..., a[v];
	long long Get(int r, int u, int v) {
		int lo = T[r].l, hi = T[r].r;

		if (v < lo || u > hi) return INT_MIN;
		if (u <= lo && hi <= v) return T[r].gmax;

		down(r);


		long long TL = Get(T[r].left, u, v);
		long long TR = Get(T[r].right, u, v);

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
		else {
			int u, v;
			cin >> u >> v;
			cout << Tree.Get(root, u, v) << '\n';
		}
	}
}