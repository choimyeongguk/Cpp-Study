#include<bits/stdc++.h>
using namespace std;
using ll = int;
using vl = vector<ll>;

struct FastScanner {
    static const int SZ = 1 << 20;
    int idx, size;
    char buf[SZ];
    FastScanner(): idx(0), size(0) {}
    char read() {
        if (idx >= size) {
            size = (int)fread(buf, 1, SZ, stdin);
            idx = 0;
            if (size == 0) return 0;
        }
        return buf[idx++];
    }
    ll nxtLL() {
        char c;
        do c = read(); while (c <= ' ' && c);
        ll sgn = 1;
        if (c == '-') { sgn = -1; c = read(); }
        ll x = 0;
        while (c > ' ') {
            x = x * 10 + (c - '0');
            c = read();
        }
        return x * sgn;
    }
    string nxtStr(ll len=-1) {
        char c;
        do c = read(); while (c <= ' ' && c);
        string str;
        if (len != -1) str.reserve(len);
        while (c > ' ') {
            str.push_back(c);
            c = read();
        }
        return str;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    FastScanner fs;
    ll N = fs.nxtLL();
    vl st; st.reserve(N);
    long long ans = 0;
    while (N--) {
        ll num = fs.nxtLL();
        while (!st.empty() && st.back()<=num) st.pop_back();
        ans += st.size();
        st.emplace_back(num);
    }
    cout << ans;
    return 0;
}