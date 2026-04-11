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

struct SegTree {
    ll n; vl tree;
    SegTree(vl& arr): n(arr.size()), tree(n<<2) {
        function<void(ll,ll,ll)> init = [&](ll i, ll s, ll e) {
            if (s == e) { tree[i] = arr[s]; return; }
            ll m = (s+e)>>1;
            init(i<<1, s, m);
            init(i<<1|1, m+1, e);
            tree[i] = tree[i<<1] + tree[i<<1|1];
        };
        init(1, 0, n-1);
    }
    void update(ll pos, ll val) { update(1, 0, n-1, pos, val); }
    void update(ll i, ll s, ll e, ll pos, ll val) {
        if (s == e) { tree[i] = val; return; }
        ll m = (s+e)>>1;
        pos<=m ? update(i<<1, s, m, pos, val) : update(i<<1|1, m+1, e, pos, val);
        tree[i] = tree[i<<1] + tree[i<<1|1];
    }
    ll query(ll l, ll r) { return query(1, 0, n-1, l, r); }
    ll query(ll i, ll s, ll e, ll l, ll r) {
        if (s>r || e<l) return 0;
        if (l<=s && e<=r) return tree[i];
        ll m = (s+e)>>1;
        return query(i<<1, s, m, l, r) + query(i<<1|1, m+1, e, l, r);
    }
};

struct HLD {
    ll n, time = 0;
    vvl& G; vl depth, sz, pa, top, in, out;
    HLD(vvl& G, ll root = 1)
        : n(G.size()), G(G),
          depth(n), sz(n), pa(n),
          top(n), in(n), out(n) {
        dfs1(root, -1);
        dfs2(root, -1, root);
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
    void dfs2(ll cur, ll prev, ll head) {
        top[cur] = head, in[cur] = time++;
        bool heavy = true;
        for (auto nxt: G[cur]) {
            if (nxt == prev) continue;
            dfs2(nxt, cur, heavy ? head : nxt);
            heavy = false;
        }
        out[cur] = time-1;
    }
    void updateNode(ll node, ll val, SegTree& seg) {
        seg.update(in[node], val);
    }
    ll queryPath(ll u, ll v, SegTree& seg) {
        ll ret = 0;
        while (top[u] != top[v]) {
            if (depth[top[u]] < depth[top[v]]) swap(u, v);
            ret += seg.query(in[top[u]], in[u]);
            u = pa[top[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        ret += seg.query(in[u], in[v]);
        return ret;
    }
};

struct DSU {
    ll n; vl sz, pa;
    DSU(ll n): n(n), sz(n, 1), pa(n) { iota(pa.begin(), pa.end(), 0); }
    ll find(ll x) {
        if (pa[x] == x) return x;
        return pa[x] = find(pa[x]);
    }
    void merge(ll x, ll y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (sz[y] > sz[x]) swap(x, y);
        pa[y] = x;
        sz[x] += sz[y];
    }
};

struct Query {
    ll op, A, B, ans;
};

void solve(ll testcase){
    ll N; io >> N;
    vl penguin(N+1); for (ll i=1; i<=N; i++) io >> penguin[i];

    ll Q; io >> Q;
    vpll edge;
    DSU dsu(N+1);
    vector<Query> query(Q);
    for (ll i=0; i<Q; i++) {
        auto& [op,A,B,ans] = query[i];
        string str;
        io >> str >> A >> B;
        switch (str[0]) {
            case 'b': op = 0; break;
            case 'p': op = 1; break;
            case 'e': op = 2; break;
        }
        if (op == 0) {
            if (dsu.find(A) != dsu.find(B)) {
                edge.emplace_back(A, B);
                dsu.merge(A, B);
                ans = true;
            }
            else ans = false;
        }
        else if (op == 2 && dsu.find(A)!=dsu.find(B))
            ans = -1;
    }

    ll idx = 0;                 // count trees
    unordered_map<ll,ll> mp;    // dsu root -> tree idx
    vl group(N+1);              // node -> tree idx
    for (ll i=1; i<=N; i++) {
        ll root = dsu.find(i);
        if (!mp.contains(root)) mp[root] = idx++;
        group[i] = mp[root];
    }

    vl size(idx, 0);       // size of tree
    vl treeIdx(N+1);            // node idx -> tree's node idx
    for (ll i=1; i<=N; i++) treeIdx[i] = size[group[i]]++;
    vector<vvl> forest(idx);    // array of trees
    for (ll i=0; i<idx; i++) forest[i].resize(size[i]);
    for (auto [u,v]: edge) {
        ll grp = group[u], nu = treeIdx[u], nv = treeIdx[v];
        forest[grp][nu].emplace_back(nv);
        forest[grp][nv].emplace_back(nu);
    }

    vector<HLD> hld;
    for (ll i=0; i<idx; i++)
        hld.emplace_back(forest[i], 0);
    vector<SegTree> seg;
    vvl arr(idx);
    for (ll i=0; i<idx; i++) arr[i].resize(size[i]);
    for (ll i=1; i<=N; i++) {
        ll grp = group[i];
        arr[grp][hld[grp].in[treeIdx[i]]] = penguin[i];
    }
    for (ll i=0; i<idx; i++)
        seg.emplace_back(arr[i]);

    for (auto [op,A,B,ans]: query) {
        ll grp = group[A];
        switch (op) {
            case 0:
                io << (ans ? "yes\n" : "no\n");
                break;
            case 1:
                hld[grp].updateNode(treeIdx[A], B, seg[grp]);
                break;
            case 2:
                if (ans == -1) io << "impossible\n";
                else {
                    ans = hld[grp].queryPath(treeIdx[A], treeIdx[B], seg[grp]);
                    io << ans << '\n';
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