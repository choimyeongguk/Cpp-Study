#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
map<ll,ll> dp;

ll fib(ll n) {
	if(n == 0) return 0;
	if(n == 1) return 1;
	if(dp.find(n) != dp.end()) return dp[n];
	
	ll f1 = fib(n / 2);
	ll f2 = fib(n / 2 - 1);
	
	if(n % 2 == 0) 
		return dp[n] = (f1 * f1 + 2 * f1 * f2) % 1000000007;
	else
		return dp[n] = (2 * f1 * (f1 + f2) + f2 * f2) % 1000000007;
}

int main() {
	ll n;
	cin >> n;
	cout << fib(n);
	return 0;
}