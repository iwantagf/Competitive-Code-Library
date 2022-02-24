#include<bits/stdc++.h>
using namespace std;

struct bit2d {
	int rows, cols;

	vector<vector<int>> bit;

	void Init(int m, int n) {
		bit.resize(m + 1, vector<int> (n + 1, 0));
		rows = m, cols = n;
	}

	void updcol(int u, int v, int D) {
		while (v <= cols) {
			bit[u][v] += D;
			v += v & (-v);
		}
	}

	void updrow(int u, int v, int D) {
		while (u <= rows) {
			updcol(u, v, D);
			u += u & (-u);
		}
	}

	int getcol(int u, int v) {
		int kq = 0;
		while (v > 0) {
			kq += bit[u][v];
			v -= v & (-v);
		}
		return kq;
	}

	int getrow(int u, int v) {
		int kq = 0;
		while (u > 0) {
			kq += getcol(u, v);
			u -= u & (-u);
		}
		return kq;
	}

};


bit2d t;


void Init() {
	int s;
	scanf("%d", &s);
	t.Init(s, s);
}

void solve1() {
	int x, y, d;
	scanf("%d%d%d", &x, &y, &d);
	++x, ++y;
	t.updrow(x, y, d);
}

void solve2() {
	int u1, v1, u2, v2;
	scanf("%d%d%d%d", &u1, &v1, &u2, &v2);
	printf("%d\n", t.getrow(u2 + 1, v2 + 1) - t.getrow(u1, v2 + 1) - t.getrow(u2 + 1, v1) + t.getrow(u1, v1));
}

int typ;

int main() {
	while (true) {
		scanf("%d", &typ);
		if (typ == 0) Init();
		else if (typ == 1) solve1();
		else if (typ == 2) solve2();
		else if (typ == 3) break;
	}
}