#include <bits/stdc++.h>
using namespace std;

map<long long, long long> dp;

long long f(long long n) {
	if(n == 0) return 0;
	if(n == 1) return 1;
	if(dp.find(n) != dp.end()) return dp[n];
	
	long long f1, f2;
	
	if(dp.find(n / 2) != dp.end()) {
		f1 = dp[n / 2];
	} else {
		f1 = f(n / 2);
		dp.insert({n / 2, f1});
	}
	if(dp.find(n / 2 - 1) != dp.end()) {
		f2 = dp[n / 2 - 1];
	} else {
		f2 = f(n / 2 - 1);
		dp.insert({n / 2 - 1, f2});
	}
	
	if(n % 2 == 0) {
		dp[n] = (f1 * f1 + 2 * f1 * f2) % 1000000007;
		return dp[n];
	} else {
		dp[n] = (2 * f1 * (f1 + f2) + f2 * f2) % 1000000007;
		return dp[n];
	}
}

int main() {
	long long n;
	cin >> n;
	cout << f(n);
	return 0;
}