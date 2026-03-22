#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vpll = vector<pll>;
using vb = vector<bool>;

#ifdef ONLINE_JUDGE
constexpr bool ndebug = true;
#define debug(x) ((void)0)
#else
constexpr bool ndebug = false;
#define debug(x) io << #x << " = " << (x) << '\n'
#endif

struct FastIO {
    static constexpr int SZ = 1 << 20;
    int idxW = 0, idxR = 0, szR = 0;
    char bufR[SZ], bufW[SZ];
    int read() {
        if (idxR >= szR) {
            szR = (int)fread(bufR, 1, SZ, stdin);
            idxR = 0;
            if (szR == 0) return -1;
        }
        return bufR[idxR++];
    }
    ll getLL() {
        int c;
        do c = read(); while (c <= ' ' && c != -1);
        bool neg = false;
        if (c == '-') { neg = true; c = read(); }
        ll x = 0;
        while ('0' <= c && c <= '9') {
            x = x * 10 + (c - '0');
            c = read();
        }
        return neg ? -x : x;
    }
    ld getLD() {
        int c; do c = read(); while (c <= ' ' && c != -1);
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = read();
        }
        ld x = 0;
        while ('0' <= c && c <= '9') {
            x = x * 10 + (c - '0');
            c = read();
        }
        if (c == '.') {
            ld base = 0.1L;
            c = read();
            while ('0' <= c && c <= '9') {
                x += (c - '0') * base;
                base *= 0.1L;
                c = read();
            }
        }
        return neg ? -x : x;
    }
    char getChar() {
        int c;
        do c = read(); while (c <= ' ' && c != -1);
        return c == -1 ? 0 : (char)c;
    }
    string getStr() {
        int c;
        do c = read(); while (c <= ' ' && c != -1);
        string str;
        while (c > ' ') {
            str.push_back((char)c);
            c = read();
        }
        return str;
    }
    string getLine() {
        int c = read();
        while (c == '\r') c = read();
        string s;
        while (c != '\n' && c != -1) {
            if (c != '\r') s.push_back((char)c);
            c = read();
        }
        return s;
    }
    void flush() {
        if (idxW) {
            fwrite(bufW, 1, idxW, stdout);
            idxW = 0;
        }
    }
    FastIO& putLL(ll x) {
        if (x == 0) { putChar('0'); return *this; }
        unsigned long long y;
        if (x < 0) putChar('-'), y = (unsigned long long)-(x+1)+1;
        else y = (unsigned long long)x;
        char s[24];
        int n = 0;
        while (y) {
            s[n++] = char('0' + y%10);
            y /= 10;
        }
        while (n--) putChar(s[n]);
        return *this;
    }
    FastIO& putLD(ld x, int precision = 12) {
        if (x < 0) {
            putChar('-');
            x = -x;
        }
        ld p10 = 1;
        for (int i = 0; i < precision; i++) p10 *= 10.0L;
        x += 0.5L / p10;
        ll intPart = (ll)x;
        putLL(intPart);
        if (precision == 0) return *this;
        x -= intPart;
        putChar('.');
        for (int i = 0; i < precision; i++) {
            x *= 10;
            int d = (int)x;
            putChar(char('0' + d));
            x -= d;
        }
        return *this;
    }
    FastIO& putChar(char c) {
        if (idxW >= SZ) flush();
        bufW[idxW++] = c;
        return *this;
    }
    FastIO& putStr(const string& s) {
        int n = (int)s.size();
        int p = 0;
        while (p < n) {
            if (idxW >= SZ) flush();
            int space = SZ - idxW;
            int take = min(space, n - p);
            memcpy(bufW + idxW, s.data() + p, take);
            idxW += take;
            p += take;
        }
        return *this;
    }
    FastIO& putStr(const char* s) {
        int n = (int)strlen(s);
        int p = 0;
        while (p < n) {
            if (idxW >= SZ) flush();
            int space = SZ - idxW;
            int take = min(space, n - p);
            memcpy(bufW + idxW, s + p, take);
            idxW += take;
            p += take;
        }
        return *this;
    }
    FastIO& operator<<(ll x) { return putLL(x); }
    FastIO& operator<<(ld x) { return putLD(x); }
    FastIO& operator<<(char c) { return putChar(c); }
    FastIO& operator<<(const string& s) { return putStr(s); }
    FastIO& operator<<(const char* s) { return putStr(s); }
    FastIO& operator>>(ll& x) { x = getLL(); return *this; }
    FastIO& operator>>(ld& x) { x = getLD(); return *this; }
    FastIO& operator>>(char& c) { c = getChar(); return *this; }
    FastIO& operator>>(string& s) { s = getStr(); return *this; }
    ~FastIO() { flush(); }
};
FastIO io;

void preprocess() {

}

using ull = uint64_t;
using u128 = unsigned __int128;

inline ull modmul(ull a, ull b, ull m) {
    return (u128)a * b % m;
}

inline ull modpow(ull a, ull e, ull m) {
    ull r = 1;
    a %= m;
    while (e) {
        if (e & 1) r = modmul(r, a, m);
        a = modmul(a, a, m);
        e >>= 1;
    }
    return r;
}

inline bool is_prime(ull n) {
    if (n<2 || n%2==0 || n%3==0) return n==2 || n==3;
    ull s = __builtin_ctzll(n-1), d = n-1 >> s;
    for (ull a : { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 }) {
        // for (ull a : { 2, 7, 61 }) {
        if (a%n == 0) continue;
        ull x = modpow(a, d, n);
        if (x==1 || x==n-1) continue;   // case 1: 전부 1 or case 2: -1 나오고 그다음 전부 1
        bool flag = true;
        for (ull r=1; r<s; r++) {
            x = modmul(x, x, n);
            if (x == n-1) { flag = false; break; }  // case 2: 중간에 -1 나오고 그다음 전부 1
            if (x == 1) return false;
        }
        if (flag) return false;
    }
    return true;
}

ull pollard_rho(ull n) {
    if ((n&1) == 0) return 2;
    if (n%3 == 0) return 3;

    function<ull(ull)> f = [&](ull x) { return (modmul(x, x, n) + 3)%n; };
    ull x=0, y=0, t=30, p=2, i=1, q=0, ret=1;
    while (t++ % 40 || (ret = gcd(p, n))==1) {
        if (x == y) x = ++i, y = f(x);  // x-y==0 을 p에 누적하면 곱 누적이 망가짐 -> 새로운 시도
        if ((q = modmul(p, x>y?x-y:y-x, n))) p=q;
        x = f(x), y = f(f(y));
    }
    return ret;
}

ll numFactor(ull n) {
    vl factor;
    function<void(ull)> getFactor = [&](ull x) {
        if (x == 1) return;
        if (is_prime(x)) { factor.emplace_back(x); return; }
        ull d = pollard_rho(x);
        getFactor(d);
        getFactor(x/d);
    };
    getFactor(n);
    sort(factor.begin(), factor.end());
    ll ret = 1, l=0, r;
    for (r=0; r<factor.size(); r++) {
        if (factor[l] != factor[r]) {
            ret *= r-l+1;
            l = r;
        }
    }
    ret *= r-l+1;
    return ret;
}

void solve(ll testcase){
    ll d, m; io >> d >> m;
    ll l=1;
    for (ll i=0; i<d; i++) {
        ll num; io >> num;
        l = lcm(l, num);
    }
    ll g; io >> g;
    for (ll i=1; i<m; i++) {
        ll num; io >> num;
        g = gcd(g, num);
    }
    if (g%l != 0) { io << 0LL; return; }
    g /= l;
    io << numFactor(g);
}

int main() {
    if(!ndebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    preprocess();
    ll t = 1;
    // io >> t;
    for (ll testcase = 1; testcase <= t; testcase++){
        solve(testcase);
    }
    return 0;
}