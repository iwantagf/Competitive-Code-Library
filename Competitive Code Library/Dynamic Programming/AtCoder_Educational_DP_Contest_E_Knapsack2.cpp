//Problem "https://oj.vnoi.info/problem/atcoder_dp_e"


#include<bits/stdc++.h>
#define fi first
#define sc second
using namespace std;
int n, w1, w[101], v[101], m = 0;
long long f[100002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> w1;

    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
        m += v[i];
    }
    for (int i = 1; i <= m; ++i) f[i] = 1e18;
    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 0; --j)
        if (f[j] + w[i] <= w1) f[j + v[i]] = min(f[j + v[i]], f[j] + w[i]);
    }

    for (int i = m; i >= 0; --i) {
        if (f[i] != 1e18) {
            cout << i;
            break;
        }
    }
}