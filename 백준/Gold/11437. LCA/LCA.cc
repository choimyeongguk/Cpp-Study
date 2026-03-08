#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
using vb = vector<bool>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vpll = vector<pll>;

#ifdef ONLINE_JUDGE
constexpr bool ndebug = true;
#else
constexpr bool ndebug = false;
#endif

void setup() {
    if(!ndebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess() {
    ll i, j, k;

}

struct FastScanner {
    static const int SZ = 1 << 15;
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

struct FastOutput {
    static const int SZ = 1 << 20;
    int idx;
    char buf[SZ];
    FastOutput(): idx(0) {}
    void flush() {
        if (idx) {
            fwrite(buf, 1, idx, stdout);
            idx = 0;
        }
    }
    void write(char c) {
        if (idx >= SZ) flush();
        buf[idx++] = c;
    }
    void writeStr(const string& s) {
        int n = (int)s.size();
        int p = 0;
        while (p < n) {
            if (idx >= SZ) flush();
            int space = SZ - idx;
            int take = min(space, n - p);
            memcpy(buf + idx, s.data() + p, take);
            idx += take;
            p += take;
        }
    }
    void writeLL(long long x) {
        if (x == 0) { write('0'); return; }
        if (x < 0) { write('-'); x = -x; }
        char s[24];
        int n = 0;
        while (x) {
            s[n++] = char('0' + (x % 10));
            x /= 10;
        }
        while (n--) write(s[n]);
    }
    void space() { write(' '); }
    void newline() { write('\n'); }
    ~FastOutput() { flush(); }
};

struct OfflineLCA {
    ll n;
    vl pa, sz, anc, vis, ans;
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
    OfflineLCA(vvl& tree, vector<vpll>& query, ll Q, ll root=0)
        : n(tree.size()), pa(n), sz(n), anc(n), vis(n, 0), ans(Q)
    {
        iota(pa.begin(), pa.end(), 0);
        function<void(ll,ll)> dfs = [&](ll cur, ll pa) {
            anc[find(cur)] = cur;
            for (auto ch : tree[cur]) {
                if (ch == pa) continue;
                dfs(ch, cur);
                merge(cur, ch);
                anc[find(cur)] = cur;
            }
            vis[cur] = true;
            for (auto [nxt, idx] : query[cur]) {
                if (vis[nxt]) ans[idx] = anc[find(nxt)];
            }
        };
        dfs(root, -1);
    }
    ll solve(ll idx) {
        return ans[idx];
    }
};

void solve(ll testcase){
    ll i, j, k;
    FastScanner fs;
    FastOutput fo;
    ll N=fs.nxtLL();
    vvl G(N+1);
    for (i=1; i<N; i++) {
        ll u=fs.nxtLL(), v=fs.nxtLL();
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    ll M=fs.nxtLL();
    vector<vpll> query(N+1);
    for (i=0; i<M; i++) {
        ll u=fs.nxtLL(), v=fs.nxtLL();
        query[u].emplace_back(v, i);
        query[v].emplace_back(u, i);
    }
    OfflineLCA lca(G, query, M, 1);
    for (i=0; i<M; i++) {
        fo.writeLL(lca.solve(i));
        fo.newline();
    }
}

int main() {
    setup();
    preprocess();
    ll t = 1;
    // cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++){
        solve(testcase);
    }
    return 0;
}