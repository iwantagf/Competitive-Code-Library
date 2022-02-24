#include<bits/stdc++.h>
#define maxn (int) 1e5 + 7
using namespace std;
int n, a[maxn], m;

struct Node {
	int left, right;
	int l, r;
	long long sum, lazy;
	Node(int lo, int hi): l(lo), r(hi) {
		left = right = -1;
		sum = 0;
		lazy = 0;
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
			T[u].sum = a[lo];
			return u;
		}

		int mid = (lo + hi)/2;

		T[u].left = Build(lo, mid);
		T[u].right = Build(mid + 1, hi);

		T[u].sum = T[T[u].left].sum + T[T[u].right].sum;
		return u;
	}


	//Transmit the values to the children
	void down(int r) {
		T[T[r].left].lazy += T[r].lazy;
		
		T[T[r].right].lazy += T[r].lazy;
		
		T[r].lazy = 0;
	}


	//Update the nodes
	void up(int r) {
		int lo = T[r].l, hi = T[r].r;
		int mid = (lo + hi)/2;
		long long Left = T[T[r].left].sum + T[T[r].left].lazy * (mid - lo + 1),
				Right = T[T[r].right].sum + T[T[r].right].lazy * (hi - mid);

		T[r].sum = Left + Right;
	}


	//Update values with lazy progpagation
	void Upd(int r, int u, int v, int val) {
		int lo = T[r].l, hi = T[r].r;

		if (v < lo || u > hi) return;

		if (u <= lo && hi <= v) {
			T[r].lazy += val;
			return;
		}

		down(r);

		Upd(T[r].left, u, v, val);
		Upd(T[r].right, u, v, val);

		up(r);
	}	


	//Get sum from a[u], ..., a[v];
	long long Get(int r, int u, int v) {
		int lo = T[r].l, hi = T[r].r;

		if (v < lo || u > hi) return 0;

		if (u <= lo && hi <= v) return T[r].sum + T[r].lazy * (hi - lo + 1);

		down(r);

		long long TL = Get(T[r].left, u, v);

		long long TR = Get(T[r].right, u, v);

		up(r);

		return TL + TR;
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