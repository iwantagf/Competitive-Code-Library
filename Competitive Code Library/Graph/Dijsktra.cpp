#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; ++i) 
#define ford(i, a, b) for (int i = a; i >= b; --i)
#define fi first
#define sc second
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;
const int maxn = 5e3 + 7;
typedef pair<int, int> II;

int m, n, k, a, b, dis[maxn];
II t[maxn];

struct Graph {
	vector<II> g[maxn];
	set<II> s;
	int siz, color[maxn], cc = 0, pre[maxn], dis[maxn], min_val[maxn];

	//Init the graph
	void Init(int n) {
		siz = n;
		rep(i, 1, n)
		rep(i, 1, n) dis[i] = pre[i] = 0;
	}


	//connect 2 edges
	void connect(int u, II v) {
		g[u].push_back(v);
	}

	//Dijsktra
	void dijsktra(int xp) {
		s.clear();
		rep(i, 1, siz) dis[i] = color[i] = 0;
		color[xp] = 1;
		pre[xp] = -1;
		s.insert(II(dis[xp], xp));

		while (!s.empty()) {
			II p = *s.begin();
			s.erase(p);
			int u = p.sc;

			color[u] = 2;
			for (auto &v : g[u]) {
				int x = v.fi;
				int w = v.sc;

				if (color[x] == 0) {
					color[x] = 1;
					dis[x] = dis[u] + w;
					s.insert(II(dis[x], x));
					pre[x] = u;
				}
				else if (color[x] == 1 && dis[x] > dis[u] + w) {
					s.erase(II(dis[x], x));
					dis[x] = dis[u] + w;
					s.insert(II(dis[x], x));
					pre[x] = u;
				}
			} 
		}
	}
};

Graph G;