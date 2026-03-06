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

void solve(ll testcase){
    ll i, j, k;
    const ll MOD = 2'000'003;
    const ll MAX = 1'455'322;   // 1'455'078 ~ 1'455'566
    ll N; cin >> N;
    priority_queue<ll,vl,greater<>> pq;  // [곱해야하는값,소수]
    vl isPrime(MAX+1, true);
    for (i=2; i<=MAX; i++) {
        if (!isPrime[i]) continue;
        pq.emplace(i);
        for (j=i*i; j<=MAX; j+=i) isPrime[j] = false;
    }
    // cout << pq.size() << "\n";
    ll ans = 1;
    for (i=0; i<N; i++) {
        auto Min = pq.top(); pq.pop();
        ans = ans*Min %MOD;
        pq.emplace(Min*Min);
    }
    cout << ans;
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