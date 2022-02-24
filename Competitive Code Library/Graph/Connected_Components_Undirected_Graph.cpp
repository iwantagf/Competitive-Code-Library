#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= b; --i)
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define maxn (int) 1e5 + 7
using namespace std;
int cc = 0;


struct Graph {
	vector<int> g[maxn], concom[maxn];
	int q[maxn], color[maxn];
	int siz;

	//connect 2 edges
	void connect(int u, int v) {
		g[u].push_back(v);
	}

	//BFS
	void BFS(int xp) {
		int l = 1, r = 0;
		q[++r] = xp;
		color[xp] = cc;
		concom[cc].push_back(xp);
		while (l <= r) {
			int u = q[l++];
			for (auto &v : g[u]) {
				if (color[v] == 0) {
					color[v] = cc;
					q[++r] = v;
					concom[cc].push_back(v);
				}
			}
		}
	}
};

Graph G;
int main() {
	int n, m;
	cin >> n >> m;
	rep(i, 1, m) {
		int u, v;
		cin >> u >> v;
		G.connect(u, v);
		G.connect(v, u);
	}

	rep(i, 1, n) {
		if (G.color[i] == 0) {
			++cc;
			G.BFS(i);
		}
	}
	cout << cc << '\n';
}