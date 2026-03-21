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
    static constexpr int SZ = 1 << 16;
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

struct BipartiteGraph {
    ll n; vl color; vvl adj;
    bool is_bipartite = true;
    ll leftSz, rightSz;
    vl leftNodes, rightNodes;   // partition idx → original idx
    vl leftId, rightId;         // original idx → partition idx
    vvl adjL;                   // left index → [right indices...]
    // maximum matching
    ll matching, distNil, INF = 1e10;
    vl pairL, pairR, dist;
    // 엣지를 바로 입력
    BipartiteGraph(ll L, ll R)
        : leftSz(L), rightSz(R), adjL(L) {}
    void add_edge(ll l, ll r) {
        adjL[l].emplace_back(r);
    }
    void erase_edge(ll ln, ll rn) {  // adjL 정렬 후 사용
        ll l = leftId[ln], r = rightId[rn];
        adjL[l].erase(lower_bound(adjL[l].begin(), adjL[l].end(), r));
    }
    // 일반 그래프 → 이분 그래프 변환
    BipartiteGraph(const vvl& G)
      : n(G.size()), adj(G), color(n, 0)
    {
        for (ll i=0; i<n; ++i) {    // 0-based index
            if (color[i] == 0 && !bfs_color(i)) {
                is_bipartite = false;
                return;
            }
        }
        build_bipartite();     // 좌우 파티션 노드 분리, 매핑, 인접 리스트 생성
    }
    bool bfs_color(ll s) {
        queue<ll> q;
        color[s] = 1;
        q.push(s);
        while (!q.empty()) {
            ll node = q.front(); q.pop();
            for (auto& nxt : adj[node]) {
                if (color[nxt] == 0) {
                    color[nxt] = -color[node];
                    q.push(nxt);
                } else if (color[nxt] == color[node])
                    return false;
            }
        }
        return true;
    }
    void build_bipartite() {
        leftId.assign(n, -1);
        rightId.assign(n, -1);
        for (ll i=0; i<n; ++i) {
            if (color[i] == 1) {
                leftId[i] = leftNodes.size();
                leftNodes.push_back(i);
            } else {
                rightId[i] = rightNodes.size();
                rightNodes.push_back(i);
            }
        }
        leftSz = leftNodes.size();
        rightSz = rightNodes.size();
        adjL.assign(leftSz, {});
        for (ll l=0; l<leftSz; ++l)
            for (auto& r : adj[leftNodes[l]])
                adjL[l].emplace_back(rightId[r]);
    }
    // maximum matching: Hopcroft-Karp
    ll max_matching() {
        matching = 0;
        pairL.assign(leftSz, -1);
        pairR.assign(rightSz, -1);
        dist.assign(leftSz, 0);
        while (bfs_HK())    // augmenting path 존재하는 동안 반복
            for (ll l=0; l<leftSz; ++l)
                if (pairL[l]==-1 && dfs_HK(l))
                    matching++;
        return matching;
    }
    bool bfs_HK() {    // 가장 짧은 augmenting path 찾음
        queue<ll> q;
        for (ll l=0; l<leftSz; l++) {
            if (pairL[l] == -1) {
                dist[l] = 0;
                q.emplace(l);
            } else dist[l] = INF;
        }
        distNil = INF;
        while (!q.empty()) {
            ll l = q.front(); q.pop();
            if (dist[l] < distNil) {
                for (auto& r : adjL[l]) {
                    ll pl = pairR[r];
                    if (pl != -1) {
                        if (dist[pl] == INF) {
                            dist[pl] = dist[l] + 1;
                            q.emplace(pl);
                        }
                    } else distNil = dist[l] + 1;
                }
            }
        }
        return distNil != INF;
    }
    bool dfs_HK(ll l) {
        for (ll r : adjL[l]) {
            ll pl = pairR[r];
            if (pl==-1 || (dist[pl]==dist[l]+1 && dfs_HK(pl))) {
                pairL[l] = r;
                pairR[r] = l;
                return true;
            }
        }
        dist[l] = INF;
        return false;
    }
    void minimum_vertex_cover() {
        queue<ll> q;
        vl visL(leftSz, false), visR(rightSz, false);
        for (ll i=0; i<leftSz; i++)
            if (pairL[i] == -1)
                q.emplace(i), visL[i] = true;
        while (!q.empty()) {
            ll l = q.front(); q.pop();
            for (auto r: adjL[l]) {
                if (r == pairL[l]) continue;
                if (!visR[r]) {
                    visR[r] = true;
                    if (pairR[r]!=-1 && !visL[pairR[r]]) {
                        q.emplace(pairR[r]);
                        visL[pairR[r]] = true;
                    }
                }
            }
        }
        vl ansL, ansR;
        for (ll i=0; i<leftSz; i++)
            if (!visL[i]) ansL.emplace_back(i);
        io << (ll)ansL.size() << " ";
        for (auto e: ansL) io << e << " ";
        for (ll i=0; i<rightSz; i++)
            if (visR[i]) ansR.emplace_back(i);
        io << "\n" << (ll)ansR.size() << " ";
        for (auto e: ansR) io << e << " ";
    }
};

void solve(ll testcase){
    ll N, M; io >> N >> M;
    BipartiteGraph bg(N+1, M+1);
    for (ll i=1; i<=N; i++) {
        ll num; io >> num;
        while (num--) {
            ll j; io >> j;
            bg.add_edge(i, j);
        }
    }
    io << bg.max_matching() << "\n";
    bg.minimum_vertex_cover();
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