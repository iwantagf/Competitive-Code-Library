//Problem "https://oj.vnoi.info/problem/atcoder_dp_h"

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int h, w, f[1001][1001];
char a[1001][1001];
bool check[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> h >> w;
    memset(check, 0, sizeof(check));
    for (int i = 1; i <= h; ++i)
    for (int j = 1; j <= w; ++j) {
        cin >> a[i][j];
        if (a[i][j] == '#') check[i][j] = true;
    }
    f[1][1] = 1;
    for (int i = 2; i <= h; ++i) f[i][1] = (check[i][1]) ? 0 : f[i - 1][1];
    for (int i = 2; i <= w; ++i) f[1][i] = (check[1][i]) ? 0 : f[1][i - 1];

    for (int i = 2; i <= h; ++i)
    for (int j = 2; j <= w; ++j) {
        if (check[i][j]) f[i][j] = 0;
        else f[i][j] = (f[i - 1][j] + f[i][j - 1]) % mod;
    }
    cout << f[h][w];
}