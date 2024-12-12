#include <bits/stdc++.h>
using namespace std;

bool sieve[4000001] = { false };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, ans, sum, l, r, i, j;
	
	cin >> N;
	for(i = 2; i * i <= N; i++) {
		if(!sieve[i]) {
			for(j = i << 1; j <= N; j += i) {
				sieve[j] = true;
			}
		}
	}
	vector<int> prime;
	for(i = 2; i <= N; i++) {
		if(!sieve[i])
			prime.emplace_back(i);
	}
	
	ans = 0, sum = 2, l = 0, r = 0;
	while(r < prime.size()) {
		if(sum < N) {
			sum += prime[++r];
		}
		else {
			if(sum == N)
				ans++;
			sum -= prime[l++];
		}
	}
	cout << ans;
	
	return 0;
}