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
    int read() {
        if (idxR >= szR) szR = (int)fread(bufR, 1, SZ, stdin), idxR = 0;
        return szR ? bufR[idxR++] : -1;
    }
    void flush() {
        if (idxW) fwrite(bufW, 1, idxW, stdout), idxW = 0;
    }
    FastIO& putChar(char c) {
        if (idxW >= SZ) flush();
        bufW[idxW++] = c;
        return *this;
    }
    FastIO& putStr(const string& s) {
        int n = (int)s.size(), p = 0;
        while (p < n) {
            if (idxW >= SZ) flush();
            int take = min(SZ - idxW, n - p);
            memcpy(bufW + idxW, s.data() + p, take);
            idxW += take, p += take;
        }
        return *this;
    }
    template <typename T>
    enable_if_t<is_integral_v<T>, T> getInt() {
        int c; do c = read(); while (c <= ' ' && c != -1);
        bool neg = false;
        if constexpr (is_signed_v<T>) if (c == '-') neg = true, c = read();
        using U = conditional_t<is_same_v<T, i128>, u128, make_unsigned_t<T>>;
        U x = 0; while ('0' <= c && c <= '9') x = x * 10 + (c - '0'), c = read();
        if constexpr (is_signed_v<T>) {
            if (neg) {
                if constexpr (is_same_v<T, i128>) {
                    return -(i128)x;
                } else {
                    return (T)-(__int128)x;
                }
            }
        }
        return (T)x;
    }
    ld getLD() {
        int c; do c = read(); while (c <= ' ' && c != -1);
        bool neg = false; if (c == '-') neg = true, c = read();
        ld x = 0; while ('0' <= c && c <= '9') x = x * 10 + (c - '0'), c = read();
        if (c == '.') {
            ld base = 0.1L;
            c = read();
            while ('0' <= c && c <= '9') x += (c - '0') * base, base *= 0.1L, c = read();
        }
        return neg ? -x : x;
    }
    char getChar() {
        int c; do c = read(); while (c <= ' ' && c != -1);
        return c == -1 ? 0 : (char)c;
    }
    string getStr() {
        int c; do c = read(); while (c <= ' ' && c != -1);
        string s; while (c > ' ') s.push_back((char)c), c = read();
        return s;
    }
    string getLine() {
        int c = read(); while (c == '\r') c = read();
        string s; while (c != '\n' && c != -1) { if (c != '\r') s.push_back((char)c); c = read(); }
        return s;
    }
    template <typename T>
    enable_if_t<is_integral_v<T>, FastIO&> putInt(T x) {
        using U = conditional_t<is_same_v<T, i128>, u128, make_unsigned_t<T>>;
        if (x == 0) { putChar('0'); return *this; }
        U y;
        if constexpr (is_signed_v<T>) {
            if (x < 0) { putChar('-'), y = (U)-(x + 1) + 1; }
            else { y = (U)x; }
        } else { y = (U)x; }
        char s[64]; int n = 0; while (y) s[n++] = char('0' + y % 10), y /= 10;
        while (n--) putChar(s[n]);
        return *this;
    }
    FastIO& putLD(ld x, int precision = 12) {
        if (x < 0) putChar('-'), x = -x;
        ld p10 = 1; for (int i = 0; i < precision; i++) p10 *= 10.0L;
        x += 0.5L / p10;
        ll intPart = (ll)x;
        putInt(intPart);
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
    template <typename T>
    enable_if_t<is_integral_v<T>, FastIO&> operator<<(T x) { return putInt(x); }
    FastIO& operator<<(ld x) { return putLD(x); }
    FastIO& operator<<(char c) { return putChar(c); }
    FastIO& operator<<(const string& s) { return putStr(s); }
    FastIO& operator<<(const char* s) { return putStr(s); }
    template <typename T>
    enable_if_t<is_integral_v<T>, FastIO&> operator>>(T& x) { x = getInt<T>(); return *this; }
    FastIO& operator>>(ld& x) { x = getLD(); return *this; }
    FastIO& operator>>(char& c) { c = getChar(); return *this; }
    FastIO& operator>>(string& s) { s = getStr(); return *this; }
    ~FastIO() { flush(); }
};
FastIO io;

void preprocess() {

}

struct MergeSortTree {
    ll n, INF = 1e18; vvl tree;
    MergeSortTree(vl& arr): n(arr.size()), tree(n<<2) {
        function<void(ll,ll,ll)> init = [&](ll i, ll s, ll e) {
            if (s == e) { tree[i] = { arr[s], INF }; return; }
            ll m = (s+e)>>1;
            init(i<<1, s, m);
            init(i<<1|1, m+1, e);
            ll l=0, r=0, lsz=tree[i<<1].size(), rsz=tree[i<<1|1].size();
            while (l<lsz && r<rsz)
                tree[i].emplace_back(tree[i<<1][l] < tree[i<<1|1][r]
                    ? tree[i<<1][l++] : tree[i<<1|1][r++]);
        };
        init(1, 0, n-1);
    }
    bool query(ll l, ll r, ll v) { return query(1, 0, n-1, l, r, v); }
    bool query(ll i, ll s, ll e, ll l, ll r, ll v) {  // v 이하 원소 개수
        if (s>r || e<l) return false;
        if (l<=s && e<=r) return binary_search(tree[i].begin(), tree[i].end(), v);
        ll m = (s+e)>>1;
        return query(i<<1, s, m, l, r, v) || query(i<<1|1, m+1, e, l, r, v);
    }
};

struct HLD {
    ll n, time = 0;
    vvl& G; vl depth, sz, pa, top, in, out;
    HLD(vvl& G, ll root = 1)
        : n(G.size()), G(G),
          depth(n), sz(n), pa(n),
          top(n, root), in(n), out(n) {
        dfs1(root, -1);
        dfs2(root, -1);
    }
    void dfs1(ll cur, ll prev) {
        sz[cur] = 1, pa[cur] = prev;
        ll heavy = -1, mx = -1;
        for (ll i=0; i<G[cur].size(); i++) {
            ll nxt = G[cur][i]; if (nxt == prev) continue;
            depth[nxt] = depth[cur] + 1;
            dfs1(nxt, cur);
            sz[cur] += sz[nxt];
            if (mx < sz[nxt]) mx = sz[nxt], heavy = i;
        }
        if (heavy != -1) swap(G[cur][0], G[cur][heavy]);
    }
    void dfs2(ll cur, ll prev) {
        in[cur] = time++;
        for (auto nxt: G[cur]) {
            if (nxt == prev) continue;
            top[nxt] = nxt==G[cur][0] ? top[cur] : nxt;
            dfs2(nxt, cur);
        }
        out[cur] = time-1;
    }
    ll queryPath(ll u, ll v, ll x, MergeSortTree& seg) {
        while (top[u] != top[v]) {
            if (depth[top[u]] < depth[top[v]]) swap(u, v);
            if (seg.query(in[top[u]], in[u], x)) return true;
            u = pa[top[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        if (seg.query(in[u], in[v], x)) return true;
        return false;
    }
};

void solve(ll testcase){
    ll N, M; io >> N >> M;
    vl val(N+1); for (ll i=1; i<=N; i++) io >> val[i];
    vvl G(N+1);
    for (ll i=1; i<N; i++) {
        ll u, v; io >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    HLD hld(G, 1);
    vl arr(N); for (ll i=1; i<=N; i++) arr[hld.in[i]] = val[i];
    MergeSortTree seg(arr);
    while (M--) {
        ll A, B, C; io >> A >> B >> C;
        io << hld.queryPath(A, B, C, seg);
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