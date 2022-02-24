//Problem "https://oj.vnoi.info/problem/atcoder_dp_n"


#include<bits/stdc++.h>

using namespace std;

int n, a[401];
long long s[401], f[401][401];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    s[0] = 0;

    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];

    f[n][n] = 0;

    for (int i = n - 1; i >= 1; --i) {
        for (int j = i + 1; j <= n; ++j) {
            f[i][j] = LONG_MAX;
            for (int k = i; k <= j - 1; ++k)
            f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
        }
    }

    cout << f[1][n];
}