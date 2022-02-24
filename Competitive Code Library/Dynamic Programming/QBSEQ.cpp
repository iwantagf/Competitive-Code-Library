//Problem "https://oj.vnoi.info/problem/qbseq"


#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 2;
int n, k, a[maxn], f[51][maxn], ds = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) f[a[i] % k][i] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            int d = a[i] % k;
            for (int t = 0; t < k; ++t)
            if (f[t][j] > 0) f[(t + d) % k][i] = max(f[(t + d) % k][i], f[t][j] + 1);
        }
    }
    for (int i = 1; i <= n; ++i) ds = max(ds, f[0][i]);
    cout << ds;
}