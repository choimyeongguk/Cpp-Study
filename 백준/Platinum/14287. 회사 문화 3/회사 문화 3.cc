#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = int;
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

struct Fenwick {
    ll n; vl tree;
    Fenwick(ll n): n(n), tree(n+1, 0) {}
    void update(ll pos, ll val) {
        for (++pos; pos<=n; pos += pos&-pos) tree[pos] += val;
    }
    ll query(ll l, ll r) { return query(r) - (l ? query(l-1) : 0); }
    ll query(ll pos) {
        ll ret = 0;
        for (++pos; pos>0; pos -= pos&-pos) ret += tree[pos];
        return ret;
    }
};

void solve(ll testcase){
    ll N, M; io >> N >> M;
    vl pa(N+1, -1);
    vvl tree(N+1);
    io >> pa[1];
    for (ll i=2; i<=N; i++) {
        io >> pa[i];
        tree[pa[i]].emplace_back(i);
    }
    ll time = 0;
    vl in(N+1, -1), out(N+1, -1);
    function<void(ll)> dfs = [&](ll cur) {
        in[cur] = time++;
        for (auto ch: tree[cur])
            dfs(ch);
        out[cur] = time;
    };
    dfs(1);
    Fenwick fw(N+1);
    while (M--) {
        ll op, i; io >> op >> i;
        switch (op) {
            case 1:
                ll w; io >> w;
                fw.update(in[i], w);
                break;
            case 2:
                io << fw.query(in[i], out[i]-1) << "\n";
                break;
        }
    }
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