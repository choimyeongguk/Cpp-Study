#include <bits/stdc++.h>
#define X 1000000007
using namespace std;
typedef long long ll;

map<ll,ll> memo;

ll power(ll b, ll x) {
	if(memo.find(x) != memo.end())
		return memo[x];
		
	ll ret = power(b, x / 2);
	if(x % 2)	// odd
		ret = ((ret * ret) % X * b) % X;
	else			// even
		ret = (ret * ret) % X;
	memo[x] = ret;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll M, N, S, gcd, ans = 0, i;
	
	cin >> M;
	for(i = 0; i < M; i++) {
		cin >> N >> S;
		memo.clear();
		memo[1] = N;
		ans = (ans + (S * power(N, X - 2)) % X) % X;
	}
	cout << ans;
	
	return 0;
}