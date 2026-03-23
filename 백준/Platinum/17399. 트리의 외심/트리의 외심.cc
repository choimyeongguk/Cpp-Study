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
    static constexpr int SZ = 1 << 22;
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
    ll N; io >> N;
    vvl G(N+1);
    for (ll i=1; i<N; i++) {
        ll x, y; io >> x >> y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    LCA lca(G, 1);
    ll Q; io >> Q;
    while (Q--) {
        ll A, B, C; io >> A >> B >> C;
        if (A==B && B==C) { io << A << "\n"; continue; }
        ll ancAB = lca.solve(A, B);
        ll ancAC = lca.solve(A, C);
        ll ancBC = lca.solve(B, C);
        ll lenAB = lca.depth[A] + lca.depth[B] - lca.depth[ancAB]*2;
        ll lenAC = lca.depth[A] + lca.depth[C] - lca.depth[ancAC]*2;
        ll lenBC = lca.depth[B] + lca.depth[C] - lca.depth[ancBC]*2;
        if (lenAB&1 || lenAC&1 || lenBC&1) { io << "-1\n"; continue; }
        ll midAB = lca.findKthAnc(lca.depth[A] > lca.depth[B] ? A : B, lenAB/2);
        if (lenAB==lenAC && lenAC==lenBC) { io << midAB << "\n"; continue; }
        ll midAC = lca.findKthAnc(lca.depth[A] > lca.depth[C] ? A : C, lenAC/2);
        ll midBC = lca.findKthAnc(lca.depth[B] > lca.depth[C] ? B : C, lenBC/2);
        if (lenAB==lenAC && lenAB>=lenBC) {   // A쪽에 치우친 경우
            ll l = lenBC/2, m = lenAB/2 - l;
            ll ancAmidBC = lca.solve(A, midBC);
            io << (lca.depth[midBC]-lca.depth[ancAmidBC] >= m
                ? lca.findKthAnc(midBC, m) : lca.findKthAnc(A, l+m)) << "\n";
            continue;
        }
        if (lenAB==lenBC && lenAB>=lenAC) {   // B쪽에 치우친 경우
            ll l = lenAC/2, m = lenAB/2 - l;
            ll ancBmidAC = lca.solve(B, midAC);
            io << (lca.depth[midAC]-lca.depth[ancBmidAC] >= m
                ? lca.findKthAnc(midAC, m) : lca.findKthAnc(B, l+m)) << "\n";
            continue;
        }
        if (lenAC==lenBC && lenAC>=lenAB) {   // C쪽에 치우친 경우
            ll l = lenAB/2, m = lenAC/2 - l;
            ll ancCmidAB = lca.solve(C, midAB);
            io << (lca.depth[midAB]-lca.depth[ancCmidAB] >= m
                ? lca.findKthAnc(midAB, m) : lca.findKthAnc(C, l+m)) << "\n";
            continue;
        }
        io << "-1\n";
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