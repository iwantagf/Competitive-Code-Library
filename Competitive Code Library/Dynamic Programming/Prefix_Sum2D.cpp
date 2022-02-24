#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= b; --i)
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

vector<vector<int>> a;

vector<vector<long long>> s;

int main() {
	fast;
	int m, n;
	cin >> m >> n;
	a.resize(m + 1, vector<int> (n + 1, 0));
	s.resize(m + 1, vector<long long> (n + 1, 0));
	rep(i, 1, m)
	rep(j, 1, n) cin >> a[i][j];
	rep(i, 1, m)
	rep(j, 1, n) s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
}