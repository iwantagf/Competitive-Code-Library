//Problem "https://oj.vnoi.info/problem/atcoder_dp_a"

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int n, h[maxn], f[maxn];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    f[1] = 0;
    f[2] = f[1] + abs(h[2] - h[1]);
    for (int i = 3; i <= n; ++i) {
        f[i] = min(f[i - 1] + abs(h[i] - h[i - 1]), f[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << f[n];
}