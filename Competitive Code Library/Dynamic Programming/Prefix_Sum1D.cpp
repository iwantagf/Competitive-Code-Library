#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= b; --i)
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

vector<int> a;

vector<long long> s;

int main() {
	fast;
	int n;
	cin >> n;
	a.resize(n + 1, 0);
	s.resize(n + 1, 0);
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) s[i] = s[i - 1] + a[i];
}