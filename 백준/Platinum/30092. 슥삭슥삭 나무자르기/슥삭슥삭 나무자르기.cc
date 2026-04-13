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

struct OfflineLCA {
    ll n; vl pa, sz, anc, vis, ans, depth;
    vector<vpll> query;
    ll find(ll x) {
        if (pa[x] == x) return x;
        return pa[x] = find(pa[x]);
    }
    void merge(ll a, ll b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        pa[b] = a;
        sz[a] += sz[b];
    }
    OfflineLCA(vvl& tree, vector<pll>& qs, ll root=1)
        : n(tree.size()), pa(n), sz(n, 1), anc(n), vis(n), ans(qs.size()), query(n, vpll()), depth(n)
    {
        iota(pa.begin(), pa.end(), 0);
        for (ll i=0; i<(ll)qs.size(); i++) {
            auto [u, v] = qs[i];
            query[u].emplace_back(v, i);
            query[v].emplace_back(u, i);
        }
        function<void(ll,ll)> dfs = [&](ll cur, ll pa) {
            anc[find(cur)] = cur;
            for (auto ch : tree[cur]) {
                if (ch == pa) continue;
                depth[ch] = depth[cur] + 1;
                dfs(ch, cur);
                merge(cur, ch);
                anc[find(cur)] = cur;
            }
            vis[cur] = true;
            for (auto [nxt, idx] : query[cur])
                if (vis[nxt]) ans[idx] = anc[find(nxt)];
        };
        dfs(root, -1);
    }
    ll solve(ll idx) {
        return ans[idx];
    }
};

struct Query {
    ll a, b, c, d;
};

struct PairHash {
    size_t operator()(const pll& p) const {
        return hash<ll>()((p.first << 32) ^ p.second);
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
    ll idx = 0;
    vpll lcaQuery;
    unordered_map<pll,ll,PairHash> mp;
    vector<Query> query(Q);
    for (auto& [a,b,c,d]: query) {
        io >> a >> b >> c >> d;
        for (auto [f,s]: vpll{{a,b}, {b,c}, {c,a}, {b,d}, {d,a}}) {
            if (f>s) swap(f, s);
            if (!mp.contains({f, s})) {
                lcaQuery.emplace_back(f, s);
                mp[{f, s}] = idx++;
            }
        }
    }
    OfflineLCA lca(G, lcaQuery, 1);
    for (auto [a,b,c,d]: query) {
        ll ab = lca.solve(mp[a<b ? pll{a, b} : pll{b,a}]);
        ll bc = lca.solve(mp[b<c ? pll{b, c} : pll{c, b}]);
        ll ca = lca.solve(mp[c<a ? pll{c, a} : pll{a, c}]);
        ll bd = lca.solve(mp[b<d ? pll{b, d} : pll{d, b}]);
        ll da = lca.solve(mp[d<a ? pll{d, a} : pll{a, d}]);
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