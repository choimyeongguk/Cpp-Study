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
    static constexpr int SZ = 1 << 21;
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

struct LCA {
    ll MAXLN;
    vl depth; vvl anc, max1, max2;
    LCA(vector<vpll>& tree, ll root=0){
        ll n = (ll)tree.size();
        MAXLN = 1; while (1<<MAXLN <= n) ++MAXLN;
        anc.assign(MAXLN,vl(n));
        max1.assign(MAXLN, vl(n, -1));
        max2.assign(MAXLN, vl(n, -1));
        // max1[i][j]=k := j의 2^i번째 조상까지 봤을 때, 최대 간선 가중치
        // max2[i][j]=k := j의 2^i번째 조상까지 봤을 때, 차대 간선 가중치
        depth.assign(n,0);
        function<void(ll,ll)> dfs = [&](ll cur,ll pa) {
            for (auto [ch,cost] : tree[cur]) {
                if (ch == pa) continue;
                depth[ch] = depth[cur] + 1;
                anc[0][ch] = cur;
                max1[0][ch] = cost;
                dfs(ch, cur);
            }
        };
        dfs(root, -1);
        anc[0][root] = root;
        ll tmp;
        for (ll i=1; i<MAXLN; i++)
            for (ll j=0; j<n; j++) {
                anc[i][j] = anc[i-1][anc[i-1][j]];
                max1[i][j] = max1[i-1][j];
                max2[i][j] = max2[i-1][j];
                if (max1[i][j] < (tmp=max1[i-1][anc[i-1][j]])) {
                    max2[i][j] = max1[i][j];
                    max1[i][j] = tmp;
                    if (max2[i][j] < (tmp=max2[i-1][anc[i-1][j]]))
                        max2[i][j] = tmp;
                }
                else if (max1[i][j]!=tmp &&  max2[i][j]<tmp) {
                    max2[i][j] = tmp;
                }
            }
    }
    pll solve(ll x, ll y){
        if (depth[x] < depth[y]) swap(x, y);
        ll u = x, v = y;
        for (ll i=MAXLN-1; i>=0; i--)
            if (depth[u]-(1LL<<i) >= depth[v])
                u = anc[i][u];
        if (u != v) {
            for (ll i=MAXLN-1; i>=0; i--)
                if (anc[i][u] != anc[i][v])
                    u = anc[i][u], v = anc[i][v];
            u = anc[0][u];
        }
        ll an = u, m1 = -1, m2 = -1;
        ll diff1 = depth[x]-depth[an], cur1 = x;
        ll diff2 = depth[y]-depth[an], cur2 = y;
        for (ll i=MAXLN-1; i>=0; i--) {
            if (diff1 & 1LL<<i) {
                vl tmp = {max1[i][cur1], max2[i][cur1]};
                for (auto e: tmp) {
                    if (m1 < e) m2 = m1, m1 = e;
                    else if (m1 > e && m2 < e) m2 = e;
                }
                cur1 = anc[i][cur1];
            }
            if (diff2 & 1LL<<i) {
                vl tmp = {max1[i][cur2], max2[i][cur2]};
                for (auto e: tmp) {
                    if (m1 < e) m2 = m1, m1 = e;
                    else if (m1 > e && m2 < e) m2 = e;
                }
                cur2 = anc[i][cur2];
            }
        }
        return {m1, m2};
    }
};

struct Edge {
    ll u, v, c;
};

void solve(ll testcase){
    ll V, E; io >> V >> E;
    vector<Edge> edges(E);
    for (auto& [u,v,c]: edges) { io >> u >> v >> c; u--, v--; }
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.c < b.c;
    });

    ll sum = 0;
    vector<vpll> tree(V);
    vector<Edge> candi; candi.reserve(max(0, E-V+1));
    vl sz(V, 1), pa(V); iota(pa.begin(), pa.end(), 0);
    function<ll(ll)> find = [&](ll x) {
        if (pa[x] == x) return x;
        return pa[x] = find(pa[x]);
    };
    function<void(ll,ll)> merge = [&](ll x, ll y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (sz[y] > sz[x]) swap(x, y);
        pa[y] = x;
        sz[x] += sz[y];
    };
    for (auto [u,v,c]: edges) {
        if (find(u) == find(v))
            candi.emplace_back(u, v, c);
        else {
            sum += c;
            tree[u].emplace_back(v, c);
            tree[v].emplace_back(u, c);
            merge(u, v);
        }
    }
    for (ll i=1; i<V; i++)
        if (find(i) != find(0)) { io << -1; return; }

    LCA lca(tree);
    ll minDiff = INT_MAX;
    for (auto [u,v,c]: candi) {
        auto [max1, max2] = lca.solve(u, v);
        if (max1 < c)
            minDiff = min(minDiff, c-max1);
        else if (max2 != -1)
            minDiff = min(minDiff, c-max2);
    }
    io << (minDiff==INT_MAX ? -1 : sum+minDiff);
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