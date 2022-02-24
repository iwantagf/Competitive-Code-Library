//Problem "https://oj.vnoi.info/problem/stmerge"


#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 2;

int m, n, c[maxn][maxn];
long long f[maxn][maxn], g[maxn][maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n;

        for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) cin >> c[i][j];

        for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= n; ++j) g[i][j] = f[i][j] = 2e18;


        g[0][0] = f[0][0] = 0;

        for (int i = 0; i <= n; ++i) f[0][i] = g[0][i] = 0;
        for (int i = 0; i <= m; ++i) f[i][0] = g[i][0] = 0;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i > 1) f[i][j] = min(g[i - 1][j] + c[i][j], f[i - 1][j]);
                else f[i][j] = g[i - 1][j] + c[i][j];
                if (j > 1) g[i][j] = min(f[i][j - 1] + c[i][j], g[i][j - 1]);
                else g[i][j] = f[i][j - 1] + c[i][j];
            }
        }
        cout << min(f[m][n], g[m][n]) << '\n';
    }
}