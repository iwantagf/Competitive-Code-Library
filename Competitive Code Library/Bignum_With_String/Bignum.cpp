#include<bits/stdc++.h>
using namespace std;

string cong(string a, string b);
string tru(string a, string b);
string nhanx(string a, string b);
string nhan(string a, string b);


string cong(string a, string b) {
    if (a[0] == '-' && b[0] != '-') return tru(b, a.erase(0, 1));
    if (a[0] != '-' && b[0] == '-') return tru(a, b.erase(0 , 1));
    if (a[0] == '-' && b[0] == '-') return '-' + cong(a.erase(0, 1), b.erase(0, 1));
    while (a.size() > 1 && a[0] == '0') a.erase(0, 1);
    while (b.size() > 1 && b[0] == '0') b.erase(0, 1);
    while (a.size() < b.size()) a = '0' + a;
    while (b.size() < a.size()) b = '0' + b;
    string res = "";
    int nho = 0;
    for (int i = a.size() - 1; i >= 0; --i) {
        int tong = int(a[i] - '0') + int(b[i] - '0') + nho;
        res = char(tong % 10 + '0') + res;
        nho = tong/10;
    }
    if (nho > 0) res = "1" + res;
    return res;
}

string tru(string a, string b) {
    if (a[0] == '-' && b[0] == '-') return tru(b.erase(0, 1), a.erase(0, 1));
    if (a[0] == '-' && b[0] != '-') return '-' + cong(a.erase(0, 1), b);
    if (a[0] != '-' && b[0] == '-') return cong(a, b.erase(0, 1));
    while (a.size() > 1 && a[0] == '0') a.erase(0, 1);
    while (b.size() > 1 && b[0] == '0') b.erase(0, 1);
    while (a.size() < b.size()) a = '0' + a;
    while (b.size() < a.size()) b = '0' + b;
    if (b > a) return '-' + tru(b, a);
    int muon = 0;

    string s = "";

    for (int i = a.size() - 1; i >= 0; --i) {
        int hieu = a[i] - b[i] - muon;
        if (hieu < 0) {
            muon = 1;
            hieu += 10;
        }
        else muon = 0;
        s = char(hieu + '0')+s;
    }
    while (s.size() > 1 && s[0] == '0') s.erase(0, 1);
    return s;
}

string nhanx(string a, int x) {
    string res = "";
    if (x == 0 || a == "0") return "0";

    int k = a.size() - 1;

    int nho = 0;

    for (int i = k; i >= 0; --i) {
        int tich = x*(a[i] - '0') + nho;
        res = char(tich % 10+'0') + res;
        nho = tich/10;
    }

    while (nho > 0) {
        res = char(nho % 10 + '0') + res;
        nho /= 10;
    }

    return res;
}

string nhan(string a, string b) {
    if (a[0] == '-' && b[0] == '-') return nhan(a.erase(0, 1), b.erase(0, 1));
    if (a[0] == '-' && b[0] != '-') return '-' + nhan(a.erase(0, 1), b);
    if (a[0] != '-' && b[0] == '-') return '-' + nhan(a, b.erase(0, 1));
    while (a.size() > 1 && a[0] == '0') a.erase(0, 1);
    while (b.size() > 1 && b[0] == '0') b.erase(0, 1);
    string res = "0";
    for (int i = b.size() - 1; i >= 0; --i) {
        string tich = nhanx(a, int(b[i] - '0'));
        for (int j = 1; j <= b.size() - i - 1; ++j) tich = tich + '0';
        res = cong(res, tich);
    }
    return res;
}



int compare(string a, string b) {
    if (a[0] == '-') {
        if (b[0] != '-') return 0;
        else {
            int res = compare(a.erase(0, 1), b.erase(0, 1));
            if (res == 1) return 1;
            else if (res == 2) return 0;
            else return 2;
        }
    }
    else {
        if (b[0] == '-') return 2;
        else {
            if (a.size() < b.size()) return 0;
            if (a.size() > b.size()) return 2;
            if (a.size() == b.size()) {
                if (a == b) return 1;
                if (a > b) return 2;
                if (a < b) return 0;
            }
        }

    }
    return 0;

}



string max_string(string a, string b) {
    if (compare(a, b) < 1) return b;
    else return a;
}



string min_string(string a, string b)  {
    if (compare(a, b) < 1) return a;
    else return b;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << cong(a, b) << '\n'
    << tru(a, b) << '\n' << nhan(a, b);
}