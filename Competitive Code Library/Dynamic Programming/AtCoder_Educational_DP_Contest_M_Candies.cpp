//Problem "https://oj.vnoi.info/problem/atcoder_dp_m"


#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int n, s = 0, k,
a[101], f[101][100002], pre[101][100002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    pre[0][0] = f[0][0] = 1;
    for (int i = 1; i <= n; ++i) pre[i][0] = f[i][0] = 1;
    for (int i = 1; i <= k; ++i) pre[0][i] = pre[0][i - 1];
    for (int i = 1; i <= n; ++i) {
        s += a[i];
        for (int j = 1; j <= min(s, k); ++j) {
            if (j > a[i]) f[i][j] = ((f[i][j] + pre[i - 1][j] - pre[i - 1][j - a[i] - 1]) % mod + mod) % mod;
            else f[i][j] = (f[i][j] + pre[i - 1][j]) % mod;
        }
        for (int j = 1; j <= k; ++j) pre[i][j] = (pre[i][j - 1] + f[i][j]) % mod;
    }


    cout << f[n][k];
}