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
using i128 = __int128_t;
using u128 = __uint128_t;

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
    int read() { if (idxR >= szR) szR = (int)fread(bufR, 1, SZ, stdin), idxR = 0; return szR ? bufR[idxR++] : -1; }
    void flush() { if (idxW)fwrite(bufW,1,idxW,stdout), idxW=0; }
    FastIO& putChar(char c) { if (idxW >= SZ) flush(); bufW[idxW++] = c; return *this; }
    FastIO& putStr(const string& s) { int n = (int)s.size(), p = 0; while (p < n) { if (idxW >= SZ) flush(); int take = min(SZ - idxW, n - p); memcpy(bufW + idxW, s.data() + p, take); idxW += take, p += take; } return *this; }
    template <typename T> enable_if_t<is_integral_v<T>, T> getInt() { int c; do c = read(); while (c <= ' ' && c != -1); bool neg = false; if constexpr (is_signed_v<T>) if (c == '-') neg = true, c = read(); using U = conditional_t<is_same_v<T, i128>, u128, make_unsigned_t<T>>; U x = 0; while ('0' <= c && c <= '9') x = x * 10 + (c - '0'), c = read(); if constexpr (is_signed_v<T>) { if (neg) { if constexpr (is_same_v<T, i128>) { return -(i128)x; } else { return (T)-(__int128)x; } } } return (T)x; }
    ld getLD() { int c; do c = read(); while (c <= ' ' && c != -1); bool neg = false; if (c == '-') neg = true, c = read(); ld x = 0; while ('0' <= c && c <= '9') x = x * 10 + (c - '0'), c = read(); if (c == '.') { ld base = 0.1L; c = read(); while ('0' <= c && c <= '9') { x += (c - '0') * base; base *= 0.1L; c = read(); } } return neg ? -x : x; }
    char getChar() { int c; do c = read(); while (c <= ' ' && c != -1); return c == -1 ? 0 : (char)c; }
    string getStr() { int c; do c = read(); while (c <= ' ' && c != -1); string s; while (c > ' ') { s.push_back((char)c); c = read(); } return s; }
    string getLine() { int c = read(); while (c == '\r') c = read(); string s; while (c != '\n' && c != -1) { if (c != '\r') s.push_back((char)c); c = read(); } return s; }
    template <typename T> enable_if_t<is_integral_v<T>, FastIO&> putInt(T x) { using U = conditional_t<is_same_v<T, i128>, u128, make_unsigned_t<T>>; if (x == 0) { putChar('0'); return *this; } U y; if constexpr (is_signed_v<T>) { if (x < 0) { putChar('-'); y = (U)(-(x + 1)) + 1; } else { y = (U)x; } } else { y = (U)x; } char s[64]; int n = 0; while (y) s[n++] = char('0' + y % 10), y /= 10; while (n--) putChar(s[n]); return *this; }
    FastIO& putLD(ld x, int precision = 12) { if (x < 0) { putChar('-'); x = -x; } ld p10 = 1; for (int i = 0; i < precision; i++) p10 *= 10.0L; x += 0.5L / p10; ll intPart = (ll)x; putInt(intPart); if (precision == 0) return *this; x -= intPart; putChar('.'); for (int i = 0; i < precision; i++) { x *= 10; int d = (int)x; putChar(char('0' + d)); x -= d; } return *this; }
    template <typename T> enable_if_t<is_integral_v<T>, FastIO&> operator<<(T x) { return putInt(x); }
    FastIO& operator<<(ld x) { return putLD(x); }
    FastIO& operator<<(char c) { return putChar(c); }
    FastIO& operator<<(const string& s) { return putStr(s); }
    FastIO& operator<<(const char* s) { return putStr(s); }
    template <typename T> enable_if_t<is_integral_v<T>, FastIO&> operator>>(T& x) { x = getInt<T>(); return *this; }
    FastIO& operator>>(ld& x) { x = getLD(); return *this; }
    FastIO& operator>>(char& c) { c = getChar(); return *this; }
    FastIO& operator>>(string& s) { s = getStr(); return *this; }
    ~FastIO() { flush(); }
};
FastIO io;

void preprocess() {

}

struct LCA {
    ll MAXLN;
    vl depth; vvl anc;
    LCA(vvl& tree, ll root=0){
        ll n = (ll)tree.size();
        MAXLN = 1;
        while (1LL<<MAXLN <= n) ++MAXLN;
        anc.assign(MAXLN,vl(n));
        depth.assign(n,0);
        function<void(ll,ll)> dfs = [&](ll cur,ll pa) {
            for (auto ch : tree[cur]) {
                if (ch == pa) continue;
                depth[ch] = depth[cur] + 1;
                anc[0][ch] = cur;
                dfs(ch, cur);
            }
        };
        dfs(root, -1);
        anc[0][root] = root;
        for (ll i=1; i<MAXLN; i++)
            for (ll j=0; j<n; j++)
                anc[i][j] = anc[i-1][anc[i-1][j]];
    }

    ll solve(ll u, ll v){
        if (depth[u] < depth[v]) swap(u, v);
        for (ll i=MAXLN-1; i>=0; i--)
            if (depth[u]-(1LL<<i) >= depth[v])
                u = anc[i][u];
        if (u == v) return u;
        for (ll i=MAXLN-1; i>=0; i--)
            if (anc[i][u] != anc[i][v])
                u = anc[i][u], v = anc[i][v];
        return anc[0][u];
    }
    ll findKthAnc(ll x, ll K) {
        for (ll i=MAXLN-1; i>=0; i--)
            if (K & 1LL<<i) x = anc[i][x];
        return x;
    }
};

void solve(ll testcase){
    ll N, Q; io >> N >> Q;
    vvl G(N+1);
    for (ll i=1; i<N; i++) {
        ll u, v; io >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    LCA lca(G, 1);
    while (Q--) {
        ll a, b, c, d; io >> a >> b >> c >> d;
        ll ab = lca.solve(a, b);
        ll bc = lca.solve(b, c), ca = lca.solve(c, a);
        ll bd = lca.solve(b, d), da = lca.solve(d, a);
        ll cc = max({ab, bc, ca}, [&](const ll& x, const ll& y) {
            return lca.depth[x] < lca.depth[y];
        });
        ll dd = max({ab, bd, da}, [&](const ll& x, const ll& y) {
            return lca.depth[x] < lca.depth[y];
        });
        io << (cc==dd ? "YES\n" : "NO\n");
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