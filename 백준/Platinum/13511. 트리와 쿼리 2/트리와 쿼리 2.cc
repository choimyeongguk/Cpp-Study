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

struct FastScanner {
    static const int SZ = 1 << 20;
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

struct LCA {
    ll MAXLN;
    vl depth, cost; vvl anc;
    LCA(vector<vpll>& tree, ll root=0) {
        ll n = (ll)tree.size();
        MAXLN = 1;
        while (1LL<<MAXLN <= n) ++MAXLN;
        anc.assign(MAXLN,vl(n));
        cost.assign(n, 0);
        depth.assign(n,0);
        function<void(ll,ll)> dfs = [&](ll cur,ll pa) {
            for (auto [ch,w] : tree[cur]) {
                if (ch == pa) continue;
                depth[ch] = depth[cur] + 1;
                cost[ch] = cost[cur] + w;
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

    ll lca(ll u, ll v){
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
    ll findKthAnc(ll pa, ll ch, ll K) { // 0-idx
        ll diff = depth[ch] - depth[pa] - K;
        for (ll i=MAXLN-1; i>=0; i--)
            if (diff & 1LL<<i) ch = anc[i][ch];
        return ch;
    }
    ll pathCost(ll u, ll v) {
        return cost[u]+cost[v] - cost[lca(u, v)]*2;
    }
    ll kthNodeOnPath(ll u, ll v, ll k) {
        ll a = lca(u, v), diff = depth[u]-depth[a]; // u가지에 있는 노드 수
        return diff>=k ? findKthAnc(a, u, diff-k+1) : findKthAnc(a, v, k-diff-1);
    }
};

void solve(ll testcase){
    ll i, j, k;
    ll N; cin >> N;
    vector<vpll> G(N+1);
    for (i=1; i<N; i++) {
        ll u, v, w; cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    LCA lca(G, 1);
    ll Q; cin >> Q;
    while (Q--) {
        ll op, u, v; cin >> op >> u >> v;
        switch (op) {
            case 1:
                cout << lca.pathCost(u, v);
                break;
            case 2:
                cin >> k;
                cout << lca.kthNodeOnPath(u, v, k);
                break;
        }
        cout << "\n";
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