//Problem "https://oj.vnoi.info/problem/linegame"

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;

int n, a[maxn];
long long f[maxn], g[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    f[0] = g[0] = 0;

    for (int i = 1; i <= n; ++i) {
        f[i] = max(f[i - 1], g[i - 1] + a[i]);
        g[i] = max(g[i - 1], f[i - 1] - a[i]);
    }

    cout << (max(f[n], g[n]));
}
