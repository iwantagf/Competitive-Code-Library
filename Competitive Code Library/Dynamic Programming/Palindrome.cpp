#include<bits/stdc++.h>
#define task "palindrome"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORDOWN(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
const int maxn = 5e3 + 6;

int n, f[maxn][maxn];
string s;

void init() {
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    fast;
    cin >> n;
    cin.ignore();
    getline(cin, s);
}
void solve() {
    FOR(k, 1, n - 1)
    FOR(i, 0, n - k - 1) {
            int j = i + k;
            if (s[i] == s[j]) f[i][j] = f[i + 1][j - 1];
            else f[i][j] = min(f[i + 1][j] + 1, f[i][j - 1] + 1);
    }
    cout << f[0][n - 1];
}
int main() {
    init();
    solve();
}
