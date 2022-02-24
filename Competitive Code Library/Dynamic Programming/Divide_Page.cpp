//Problem "https://oj.vnoi.info/problem/ptrang"


#include<bits/stdc++.h>
using namespace std;

int n, l, w[6001], f[6001], s[6001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> l;

    for (int i = 1; i <= n; ++i) cin >> w[i];

    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + w[i];

    f[0] = 0;
    f[1] = l - w[1];
    for (int i = 2; i <= n; ++i) {
        f[i] = max(f[i - 1], l - w[i]);
        for (int j = 1; j < i; ++j)
        if (s[i] - s[j - 1] <= l)
        f[i] = min(f[i], max(f[j - 1], l - (s[i] - s[j - 1])));
    }

    cout << f[n];
}