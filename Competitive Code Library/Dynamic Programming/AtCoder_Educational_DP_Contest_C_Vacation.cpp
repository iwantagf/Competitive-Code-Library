//Problem "https://oj.vnoi.info/problem/atcoder_dp_c"

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int n, a[maxn], b[maxn], c[maxn],
f[maxn], q[maxn], t[maxn];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i] >> c[i];
    f[1] = a[1];
    q[1] = b[1];
    t[1] = c[1];
    for (int i = 2; i <= n; ++i) {
        f[i] = max(q[i - 1] + a[i], t[i - 1] + a[i]);
        q[i] = max(f[i - 1] + b[i], t[i - 1] + b[i]);
        t[i] = max(f[i - 1] + c[i], q[i - 1] + c[i]);
    }

    cout << (max({f[n], q[n], t[n]}));
}