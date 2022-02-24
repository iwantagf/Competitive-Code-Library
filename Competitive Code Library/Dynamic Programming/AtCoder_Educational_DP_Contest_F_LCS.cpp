//Problem "https://oj.vnoi.info/problem/atcoder_dp_f"

#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
char x[3005];
string a, b;
int m, n, f[3005][3005];
int main() {
    fast;
    getline(cin, a);
    getline(cin, b);
    m = a.size();
    n = b.size();
    for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) {
        if (a[i - 1] == b[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
        else f[i][j] = max(f[i - 1][j], max(f[i][j - 1], f[i - 1][j - 1]));
    }
    int u = m, v = n, slx = 0;
    while (u > 0 && v > 0) {
        if (a[u - 1] == b[v - 1]) {
            x[++slx] = a[u - 1];
            --u, --v;
        }
        else if (f[u][v] == f[u][v - 1]) --v;
        else --u;
    }
    for (int i = slx; i >= 1; --i) cout << x[i];
}