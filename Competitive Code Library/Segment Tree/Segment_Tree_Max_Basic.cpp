#include<bits/stdc++.h>
using namespace std;
#define maxn (int) 1e5 + 2

int n, q;

vector<int> a;

struct STMAX {
	struct Node {
		int left, right;
		int gmax;
		int l, r;
	};

	vector<Node> T;

	int NewNode() {
		Node a;
		a.left = a.right = a.l = a.r = 0;
		a.gmax = INT_MIN;
		T.push_back(a);
		return T.size() - 1;
	}

	int Build(int lo, int hi) {
		int u = NewNode();
		T[u].l = lo, T[u].r = hi;
		
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

	void Upd(int r, int u, int val) {
		int lo = T[r].l, hi = T[r].r;
		if (u < lo || u > hi) return;

		if (lo == hi) {
			T[r].gmax = val;
			return;
		}

		int mid = (lo + hi)/2;

		if (u <= mid) Upd(T[r].left, u, val);
		else Upd(T[r].right, u, val);

		T[r].gmax = max(T[T[r].left].gmax, T[T[r].right].gmax);
	}


	int Get(int r, int u, int v) {
		int lo = T[r].l, hi = T[r].r;

		if (v < lo || u > hi) return INT_MIN;
		if (u <= lo && hi <= v) return T[r].gmax;

		int TL = Get(T[r].left, u, v);
		int TR = Get(T[r].right, u, v);

		return max(TL, TR);
	}


};

STMAX Tree;


int main() {
	cin.tie(0) -> ios::sync_with_stdio(0);

	cin >> n;
	a.resize(n + 1, 0);
	
	for (int i = 1; i <= n; ++i) cin >> a[i];

	int root = Tree.Build(1, n);

	cin >> q;

	while (q--) {
		int loai;
		cin >> loai;

		if (loai == 1) {
			int u, V;

			cin >> u >> V;

			Tree.Upd(root, u, V);
		}

		else if (loai == 2) {
			int u, v;

			cin >> u >> v;

			cout << Tree.Get(root, u, v) << '\n';
		}
	}

}