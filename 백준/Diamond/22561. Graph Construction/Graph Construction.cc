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

struct ODC {
    struct RollbackDSU {
        vl pa, sz; stack<pll> st;
        RollbackDSU(ll n): pa(n+1), sz(n+1, 1) { iota(pa.begin(), pa.end(), 0); }
        ll find(ll x) { while (x != pa[x]) x = pa[x]; return x; }
        void merge(ll x, ll y) {
            x = find(x), y = find(y);
            if (x == y) { st.emplace(-1, -1); return; }
            if (sz[x] < sz[y]) swap(x, y);
            st.emplace(y, sz[x]);
            pa[y] = x, sz[x] += sz[y];
        }
        ll snapshot() { return st.size(); }
        void rollback(ll snap) {
            while (st.size() > snap) {
                auto [ch, prevSz] = st.top(); st.pop();
                if (ch == -1) continue;
                sz[pa[ch]] = prevSz, pa[ch] = ch;
            }
        }
    };
    struct PairHash {
        size_t operator()(const pll& p) const {
            return hash<ll>()((p.first << 32) ^ p.second);
        }
    };
    ll n, q, time = 0;
    vl ans; vpll query; vector<vpll> seg;
    unordered_map<pll,ll,PairHash> mp;
    ODC(ll n, ll q): n(n), q(q), ans(q, -1), query(q, {-1, -1}), seg(q<<2) {}
    bool addEdge(ll u, ll v, bool init=false) {
        pll e = u < v ? pll{ u, v } : pll{ v, u };
        if (mp.contains(e)) return false;
        mp[e] = time;
        if (!init) time++;
        return true;
    }
    bool eraseEdge(ll u, ll v) {
        pll e = u < v ? pll{ u, v } : pll{ v, u };
        auto it = mp.find(e);
        if (it == mp.end()) return false;
        updateEdge(1, 0, q-1, it->second, time++-1, e);
        mp.erase(it);
        return true;
    }
    void updateEdge(ll i, ll s, ll e, ll l, ll r, pll edge) {
        if (s>r || e<l) return;
        if (l<=s && e<=r) { seg[i].emplace_back(edge); return; }
        ll m = (s+e)>>1;
        updateEdge(i<<1, s, m, l, r, edge);
        updateEdge(i<<1|1, m+1, e, l, r, edge);
    }
    void addQuery(ll u, ll v) {
        query[time++] = u < v ? pll{ u, v } : pll{ v, u };
    }
    void solve() {
        for (auto [e,start]: mp)
            updateEdge(1, 0, q-1, start, q-1, e);
        RollbackDSU dsu(n);
        function<void(ll,ll,ll)> dfs = [&](ll i, ll s, ll e) {
            ll snap = dsu.snapshot();
            for (auto [u,v] : seg[i]) dsu.merge(u, v);
            if (s == e) {
                if (query[s].first != -1)
                    ans[s] = dsu.find(query[s].first) == dsu.find(query[s].second);
            } else {
                ll m = (s+e)>>1;
                dfs(i<<1, s, m);
                dfs(i<<1|1, m+1, e);
            }
            dsu.rollback(snap);
        };
        dfs(1, 0, q-1);
    }
};

void solve(ll testcase){
    ll N, Q; io >> N >> Q;
    ODC odc(N, Q);
    ll op, u, v;
    while (Q--) {
        io >> op >> u >> v;
        switch (op) {
            case 1:
                odc.addEdge(u, v);
                break;
            case 2:
                odc.eraseEdge(u, v);
                break;
            case 3:
                odc.addQuery(u, v);
                break;
        }
    }
    odc.solve();
    for (auto e: odc.ans) {
        if (e != -1)
            io << (e ? "YES\n" : "NO\n");
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