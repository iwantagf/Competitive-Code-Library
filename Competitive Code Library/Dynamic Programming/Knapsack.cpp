#include<bits/stdc++.h>
#define fi first
#define sc second
using namespace std;
int n, m, tong = 0;
int w[102], v[102];
int64_t f[102][100002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> w[i] >> v[i];
    for (int i = 1; i <= m; ++i) f[0][i] = 0;
    for (int i = 1; i <= n; ++i) f[i][0] = 0;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
        f[i][j] = f[i-1][j];
        if (j >= w[i]) f[i][j] = max(f[i-1][j], v[i] + f[i - 1][j - w[i]]);
    }
    cout << f[n][m];
}