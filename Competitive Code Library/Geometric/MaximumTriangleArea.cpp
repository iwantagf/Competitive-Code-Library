#include<bits/stdc++.h>
#define task ""
#define fi first
#define sc second
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define pi acos(-1)
#define EP 1.0e-4
using namespace std;
int n, m;
typedef pair<double, double> Tpoint;
Tpoint a[3001], b[3001];
Tpoint operator+ (Tpoint A, Tpoint B) {
    return {A.fi + B.fi, A.sc + B.sc};
}

Tpoint operator- (Tpoint A, Tpoint B) {
    return {A.fi - B.fi, A.sc - B.sc};
}

Tpoint operator* (double k, Tpoint A) {
    return {A.fi*k, A.sc*k};
}

double dot(Tpoint A, Tpoint B) {
    return A.fi*B.fi + A.sc*B.sc;
}

double Cross(Tpoint A, Tpoint B) {
    return A.fi*B.sc - A.sc*B.fi;
}

int ccw(Tpoint a, Tpoint b, Tpoint c) {
    double T = Cross(b - a, c - a);
    if (T > 0) return 1; // turn left
    if (T < 0) return -1; // turn right
    return 0; // go xi tray
}

void init() {
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    fast;
    cin >> n;
    FOR(i, 1, n) cin >> a[i].fi >> a[i].sc;
    sort(a + 1, a + n + 1);
    m = 2, b[1] = a[1], b[2] = a[2];
}

double sq(Tpoint x, Tpoint y, Tpoint z) {
    return 1.0/2*abs(Cross(x - y, x - z));
}

void solve() {
    //3 points of the triangle are 3 points of convex 
    FOR(i, 3, n) {
        while (m > 1 && ccw(b[m - 1], b[m], a[i]) <= 0) --m;
        b[++m] = a[i];
    }
    int m1 = m;
    FORD(i, n - 1, 1) {
        while (m > m1 && ccw(b[m - 1], b[m], a[i]) <= 0) --m;
        b[++m] = a[i];
    }
    --m;
    double ds = 0;
    FOR(i, 1, m - 2) {
        int j = i + 1;
        int k = j + 1;
        while (k < m && sq(b[i], b[j], b[k]) < sq(b[i], b[j], b[k + 1])) ++k;
        ds = max(ds, sq(b[i], b[j], b[k]));
        FOR(j, i + 2, m - 1) {
            while (k < m && sq(b[i], b[j], b[k]) < sq(b[i], b[j], b[k + 1])) ++k;
            ds = max(ds, sq(b[i], b[j], b[k]));
        }
    }
    cout << ds;

}

int main() {
    init();
    solve();
}