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

ll p;

inline ll modmul(ll a, ll b) {
    return (__int128)a * b % p;
}

inline ll modpow(ll a, ll e) {
    ll r = 1;
    a %= p;
    while (e) {
        if (e & 1) r = modmul(r, a);
        a = modmul(a, a);
        e >>= 1;
    }
    return r;
}

vl fac, invfac;

void init_fact() {
    fac.assign(p, 1);
    invfac.assign(p, 1);
    for (ll i=1; i<p; i++)
        fac[i] = fac[i - 1] * i %p;

    invfac[p-1] = modpow(fac[p-1], p-2);
    for (ll i=p-1; i-->0;)
        invfac[i] = invfac[i+1] * (i+1) %p;
}

inline ll binomial(ll n, ll m) {
    if (m < 0 || m > n) return 0;
    return fac[n] * invfac[m] %p * invfac[n-m] %p;
}

inline ll lucas(ll n, ll m){
    if(m<0 || m>n) return 0;
    ll res = 1;
    while (n>0 || m>0) {
        ll n_i = n %p, m_i = m %p;
        if (m_i > n_i) return 0;
        res = res * binomial(n_i, m_i) %p;
        n /= p, m /= p;
    }
    return res;
}

ll MOD;

vl combine(const vl& a, const vl& b, const vl& C) {
    ll d = C.size();
    vl t(2*d-1, 0);
    for (ll i=0; i<d; i++)  // 두 다항식을 곱하는 과정
        for (ll j=0; j<d; j++)
            t[i+j] = (t[i+j] + a[i]*b[j]) %MOD;
    for (ll i = 2*d-2; i >= d; i--) // 차수 d이상인 항을 낮은 항으로 변환
        if (t[i]) for (ll j=1; j<=d; j++)
            t[i-j] = (t[i-j] + t[i]*C[j-1]) %MOD;
    t.resize(d);
    return t;
}

ll kitamasa(ll n, const vl& init, const vl& C) {
    ll d = C.size();
    if (d == 1) {   // a[n] = C[0]*a[n-1] = C[0]^n & a[0]
        ll pw = 1, base = C[0];
        while (n > 0) {
            if (n & 1) pw = pw * base %MOD;
            base = base * base %MOD;
            n >>= 1;
        }
        return init[0] * pw %MOD;
    }
    if (n < d) return init[n] %MOD;
    vl res(d, 0), base(d, 0);
    res[0] = 1, base[1] = 1;    // polynomial 1, x
    while (n > 0) {
        if (n & 1) res = combine(res, base, C);
        base = combine(base, base, C);
        n >>= 1;
    }
    ll ans = 0;
    for (ll i=0; i<d; i++)
        ans = (ans + res[i]*init[i]) %MOD;
    return ans;
}

void solve(ll testcase){
    ll N, M, K; io >> N >> M >> K >> p;
    MOD = p;
    init_fact();
    ll d = N + 2*M;
    if (d==0) { io << 0ll; return; }
    if (d==1) { io << 1ll; return; }
    vl a(d); a[0] = 1, a[1] = N;
    for (ll i=2; i<d; i++)
        for (ll j=i/2; j>=0; j--) {
            ll t1 = M==0 ? j==0 : lucas(M+j-1, j);
            ll t2 = N==0 ? i-2*j==0 : lucas(i-2*j+N-1, i-2*j);
            a[i] = (a[i] + t1*t2 %p) %p;
        }
    if (K < d) { io << a[K]; return; }

    vl q(d, 0);
    for (ll i=1; i<=d; i++) {
        for (ll j=0; j<=i; j++) {
            ll tmp = lucas(M, j) * lucas(N+M, i-j) %p;
            if (i-j & 1) tmp = p-tmp;
            q[i-1] = (q[i-1] - tmp + p) %p;
        }
    }
    io << kitamasa(K, a, q);
}

int main() {
    if(!ndebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    ll t = 1;
    // io >> t;
    for (ll testcase = 1; testcase <= t; testcase++){
        solve(testcase);
    }
    return 0;
}