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
    ll nextInt() {
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
};

void solve(ll testcase){
    ll i, j, k;
    FastScanner fs;
    ll N = fs.nextInt();
    ll a = fs.nextInt(), b = fs.nextInt(), e = 0;
    while (--N) {
        ll c = fs.nextInt(), d = fs.nextInt();
        e += a*d + b*c;
        a += c, b += d;
    }
    cout << e;
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