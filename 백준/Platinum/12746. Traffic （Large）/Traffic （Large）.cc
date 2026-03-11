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

#ifdef ONLINE_JUDGE
constexpr bool ndebug = true;
#else
constexpr bool ndebug = false;
#endif

struct FastIO {
    static const int SZ = 1 << 20;
    int idxW = 0, idxR = 0, szR = 0;
    char bufR[SZ], bufW[SZ];
    char Ch() {
        if (idxR >= szR) {
            szR = (int)fread(bufR, 1, SZ, stdin);
            idxR = 0;
            if (szR == 0) return 0;
        }
        return bufR[idxR++];
    }
    ll LL() {
        char c;
        do c = Ch(); while (c <= ' ' && c);
        ll sgn = 1;
        if (c == '-') { sgn = -1; c = Ch(); }
        ll x = 0;
        while (c > ' ') {
            x = x*10 + (c-'0');
            c = Ch();
        }
        return x*sgn;
    }
    string Str(int len=-1) {
        char c;
        do c = Ch(); while (c <= ' ' && c);
        string str;
        if (len != -1) str.reserve(len);
        while (c > ' ') {
            str.push_back(c);
            c = Ch();
        }
        return str;
    }
    void flush() {
        if (idxW) {
            fwrite(bufW, 1, idxW, stdout);
            idxW = 0;
        }
    }
    FastIO& wr(char c) {
        if (idxW >= SZ) flush();
        bufW[idxW++] = c;
        return *this;
    }
    FastIO& wr(const string& s) {
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
    FastIO& wr(ll x) {
        if (x == 0) { wr('0'); return *this; }
        if (x < 0) { wr('-'); x = -x; }
        char s[24];
        int n = 0;
        while (x) {
            s[n++] = char('0' + x%10);
            x /= 10;
        }
        while (n--) wr(s[n]);
        return *this;
    }
    FastIO& sp() { wr(' '); return *this; }
    FastIO& nl() { wr('\n'); return *this; }
};
FastIO io;

void preprocess() {
    ll i, j, k;

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
};

void solve(ll testcase){
    ll i, j, k;
    ll N=io.LL(), Q=io.LL();
    vvl G(N+1);
    for (i=1; i<N; i++) {
        ll a=io.LL(), b=io.LL();
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    LCA lca(G, 1);
    vl memo(N+1, 0);
    for (i=0; i<Q; i++) {
        ll u=io.LL(), v=io.LL();
        memo[lca.solve(u, v)]-=2, memo[u]++, memo[v]++;
    }
    ll a=-1, b=-1, c=0;
    function<void(ll,ll)> dfs = [&](ll cur, ll pa) {
        for (auto ch: G[cur]) {
            if (ch == pa) continue;
            dfs(ch, cur);
            memo[cur] += memo[ch];
            ll f=min(cur, ch), s=max(cur, ch);
            if (c<memo[ch] || (c==memo[ch] && (a>f || (a==f && b>s))))
                c=memo[ch], a=f, b=s;

        }
    };
    dfs(1, -1);
    io.wr(a).sp().wr(b).sp().wr(c);
}

int main() {
    if(!ndebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    preprocess();
    ll t = 1;
    // ll t = getLL();
    for (ll testcase = 1; testcase <= t; testcase++){
        solve(testcase);
    }
    io.flush();
    return 0;
}