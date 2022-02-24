#include<bits/stdc++.h>
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
Tpoint a[200001], b[200001];
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
    return 0; // go straight
}

void init() {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%lf%lf", &a[i].fi, &a[i].sc);
    sort(a + 1, a + n + 1);
    m = 2, b[1] = a[1], b[2] = a[2];
}

void solve() {
    FOR(i, 3, n) {
        while (m > 1 && ccw(b[m - 1], b[m], a[i]) <= 0) --m;
        b[++m] = a[i];
    }
    int m1 = m;
    FORD(i, n - 1, 1) {
        while (m > m1 && ccw(b[m - 1], b[m], a[i]) <= 0) --m;
        b[++m] = a[i];
    }
}

int main() {
    init();
    solve();
}
