#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= b; --i)
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define maxn (int) 1e5 + 7
using namespace std;



struct Graph {
	vector<vector<int>> g;
	vector<int> q, color;
	int siz;


	//Init The Graph
	Graph(int n): siz(n) {
		g.resize(n + 1, vector<int> ());
		q.resize(n + 1, 0);
		color.resize(n + 1, 0);
	}


	//connect 2 edges
	void connect(int u, int v) {
		g[u].push_back(v);
	}

	//BFS
	void BFS(int xp) {
		int l = 1, r = 0;
		q[++r] = xp;
		color[xp] = 1;
		while (l <= r) {
			int u = q[l++];
			for (auto &v : g[u]) {
				if (color[v] == 0) {
					color[v] = 1;
					q[++r] = v;
				}
			}
		}
	}
};


int main() {
	//do something here
}