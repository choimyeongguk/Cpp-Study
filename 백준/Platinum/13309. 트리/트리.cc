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

struct LazySeg {
    ll n; vl lazy;   // 터진 조상 중 가장 깊은 깊이
    LazySeg(ll n): n(n), lazy(n<<2) {}
    void push(ll i) {
        if (lazy[i] == 0) return;
        lazy[i<<1] = max(lazy[i<<1], lazy[i]);
        lazy[i<<1|1] = max(lazy[i<<1|1], lazy[i]);
        lazy[i] = 0;
    }
    void update(ll l, ll r, ll d) { update(1, 0, n-1, l, r, d); }
    void update(ll i, ll s, ll e, ll l, ll r, ll d) {
        if (s>r || e<l) return;
        if (l<=s && e<=r) { lazy[i] = max(lazy[i], d); return; }
        push(i);
        ll m = (s+e)>>1;
        update(i<<1, s, m, l, r, d);
        update(i<<1|1, m+1, e, l, r, d);
    }
    ll query(ll pos) { return query(1, 0, n-1, pos); }
    ll query(ll i, ll s, ll e, ll pos) {
        if (s == e) return lazy[i];
        push(i);
        ll m = (s+e)>>1;
        return pos<=m ? query(i<<1, s, m, pos) : query(i<<1|1, m+1, e, pos);
    }
};

void solve(ll testcase){
    ll N, Q; io >> N >> Q;
    vl pa(N+1, -1); vvl G(N+1);
    for (ll i=2; i<=N; i++)
        G[pa[i] = io.getLL()].emplace_back(i);
    ll time = 0; vl in(N+1), out(N+1);
    ll MAXLN=1; while (1LL<<MAXLN <= N+1) ++MAXLN;
    vl depth(N+1, 0); vvl anc(MAXLN, vl(N+1));
    function<ll(ll,ll)> solve = [&](ll u, ll v){
        if (depth[u] < depth[v]) swap(u, v);
        for (ll i=MAXLN-1; i>=0; i--)
            if (depth[u]-(1LL<<i) >= depth[v])
                u = anc[i][u];
        if (u == v) return u;
        for (ll i=MAXLN-1; i>=0; i--)
            if (anc[i][u] != anc[i][v])
                u = anc[i][u], v = anc[i][v];
        return anc[0][u];
    };
    function<void(ll)> dfs = [&](ll cur) {
        in[cur] = time++;
        for (auto ch: G[cur]) {
            depth[ch] = depth[cur] + 1;
            anc[0][ch] = cur;
            dfs(ch);
        }
        out[cur] = time;
    };
    dfs(1);
    anc[0][1] = 1;
    for (ll i=1; i<MAXLN; i++)
        for (ll j=0; j<=N; j++)
            anc[i][j] = anc[i-1][anc[i-1][j]];

    LazySeg seg(N);
    while (Q--) {
        ll u, v, op; io >> u >> v >> op;
        bool hasPath = depth[solve(u, v)] >= max(seg.query(in[u]), seg.query(in[v]));
        switch (op) {
            case 0:
                io << (hasPath ? "YES\n" : "NO\n");
                break;
            case 1:
                if (hasPath) {
                    io << "YES\n";
                    if (pa[u] != -1) {
                        pa[u] = -1;
                        seg.update(in[u], out[u]-1, depth[u]);
                    }
                }
                else {
                    io << "NO\n";
                    if (pa[v] != -1) {
                        pa[v] = -1;
                        seg.update(in[v], out[v]-1, depth[v]);
                    }
                }
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