#include<bits/stdc++.h>
#define fi first
#define sc second
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
using namespace std;

const int maxn = 1e5 + 4;

int m, n, a[maxn];

//Max from 1 to u
struct BIT {
    vector<int> b;

    void Init(int n) {
        b.resize(n + 1, INT_MIN);
    }

    void update(int u, int D) {
        while (u <= n) {
            b[u] = max(b[u], D);
            u += u & (-u);
        }
    }

    int get(int u) {
        int kq = INT_MIN;
        while (u > 0) {
            kq = max(kq, b[u]);
            u -= u & (-u);
        }
        return kq;
    }
};


//Max from u to n
struct BIT {
    vector<int> b;

    void Init(int n) {
        b.resize(n + 1, INT_MIN);
    }

    void update(int u, int D) {
        while (u > 0) {
            b[u] = max(b[u], D);
            u -= u & (-u);
        }
    }

    int get(int u) {
        int kq = INT_MIN;
        while (u <= n) {
            kq = max(kq, b[u]);
            u += u & (-u);
        }
        return kq;
    }
};


//Use only 1 BIT (please :>)
BIT T;

void solve1() {
    int u, v;
    cin >> u >> v;
    a[u] += v;
    T.update(u, a[u]);
}

void solve2() {
    int u;
    cin >> u;
    cout << T.get(u) << '\n';
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    T.Init(n);
    FOR(i, 1, n) {
        cin >> a[i];
        T.update(i, a[i]);
    }
    cin >> m;
    while (m--) {
        int loai;
        cin >> loai;
        if (loai == 1) solve1();
        else solve2();
    }
}
