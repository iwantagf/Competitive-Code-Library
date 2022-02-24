#include<bits/stdc++.h>
#define task ""
#define fi first
#define sc second
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
const int maxn = 1e5 + 4;
using namespace std;

int a[maxn];
int m, n;

struct BIT {
    vector<long long> b;
    int siz;

    //Init The Tree
    void Init(int n) {
    	b.resize(n + 1, 0);
    	siz = n;
    }

    //Update nodes of the tree
    void update(int u, int delta) {
        while (u <= siz) {
            b[u] += delta;
            u += u & (-u);
        }
    }


    //Get sum from a[1], a[2], ..., a[u]
    long long get(int u) {
        long long kq = 0;
        while (u > 0) {
            kq += b[u];
            u -= u & (-u);
        }
        return kq;
    }
};

BIT T;


void solve1() {
    int u, D;
    cin >> u >> D;
    a[u] += D;
    T.update(u, D);
}

void solve2() {
    int u, V;
    cin >> u >> V;
    int D = V - a[u];
    a[u] = V;
    T.update(u, D);
}

void solve3() {
    int u, v;
    cin >> u >> v;
    cout << T.get(v) - T.get(u - 1) << '\n';
}


int main() {
    fast;
    cin >> n;
    T.Init(n);
    FOR(i, 1, n) {
        cin >> a[i];
        T.update(i, a[i]);
    }
    cin >> m;
    while (m--) {
        int typ;
        cin >> typ;
        if (typ == 1) solve1();
        else if (typ == 2) solve2();
        else if (typ == 3) solve3();
    }
}

