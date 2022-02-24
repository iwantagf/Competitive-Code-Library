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

typedef pair<double, double> Tpoint;

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

int t;
Tpoint a, b, c, d;

bool check(Tpoint a, Tpoint b, Tpoint c, Tpoint d) {
    if (Cross(a - c, a - d) == 0 && dot(a - c, a - d) <= 0) return true;
    if (Cross(b - c, b - d) == 0 && dot(b - c, b - d) <= 0) return true;
    if (Cross(c - a, c - b) == 0 && dot(c - a, c - b) <= 0) return true;
    if (Cross(d - a, d - b) == 0 && dot(d - a, d - b) <= 0) return true;
    if (ccw(a, b, c) * ccw(a, b, d) < 0 && ccw(c, d, a) * ccw(c, d, b) < 0) return true;
    return false;
}

void init() {
    fast;
    cin >> t;
}

void solve() {
    while (t--) {
        cin >> a.fi >> a.sc
        >> b.fi >> b.sc
        >> c.fi >> c.sc
        >> d.fi >> d.sc;
        if (check(a, b, c, d)) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    init();
    solve();
}
