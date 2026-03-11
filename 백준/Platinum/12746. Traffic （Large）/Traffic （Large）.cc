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

constexpr int SZ = 1 << 20;
int Ridx = 0, Rsz = 0, Widx;
char Rbuf[SZ], Wbuf[SZ];
char getCh();
ll getLL();
string getStr(ll);
void flush();
void write(char);
void write(ll);
void write(const string&);
void sp();
void nl();

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
    ll N=getLL(), Q=getLL();
    vvl G(N+1);
    for (i=1; i<N; i++) {
        ll a=getLL(), b=getLL();
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    LCA lca(G, 1);
    vl memo(N+1, 0);
    for (i=0; i<Q; i++) {
        ll u=getLL(), v=getLL();
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
    write(a), sp(), write(b), sp(), write(c);
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
    flush();
    return 0;
}

char getCh() {
    if (Ridx >= Rsz) {
        Rsz = (int)fread(Rbuf, 1, SZ, stdin);
        Ridx = 0;
        if (Rsz == 0) return 0;
    }
    return Rbuf[Ridx++];
}
ll getLL() {
    char c;
    do c = getCh(); while (c <= ' ' && c);
    ll sgn = 1;
    if (c == '-') { sgn = -1; c = getCh(); }
    ll x = 0;
    while (c > ' ') {
        x = x*10 + (c-'0');
        c = getCh();
    }
    return x*sgn;
}
string getStr(ll len=-1) {
    char c;
    do c = getCh(); while (c <= ' ' && c);
    string str;
    if (len != -1) str.reserve(len);
    while (c > ' ') {
        str.push_back(c);
        c = getCh();
    }
    return str;
}
void flush() {
    if (Widx) {
        fwrite(Wbuf, 1, Widx, stdout);
        Widx = 0;
    }
}
void write(char c) {
    if (Widx >= SZ) flush();
    Wbuf[Widx++] = c;
}
void write(const string& s) {
    int n = (int)s.size();
    int p = 0;
    while (p < n) {
        if (Widx >= SZ) flush();
        int space = SZ - Widx;
        int take = min(space, n - p);
        memcpy(Wbuf + Widx, s.data() + p, take);
        Widx += take;
        p += take;
    }
}
void write(ll x) {
    if (x == 0) { write('0'); return; }
    if (x < 0) { write('-'); x = -x; }
    char s[24];
    int n = 0;
    while (x) {
        s[n++] = char('0' + x%10);
        x /= 10;
    }
    while (n--) write(s[n]);
}
void sp() { write(' '); }
void nl() { write('\n'); }