#include <bits/stdc++.h>
using namespace std;

bool sieve[4000001] = { false };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, ans, sum, l, r, i, j;
	vector<int> prime;
	
	for(i = 2; i <= 2000; i++) {
		if(!sieve[i]) {
			for(j = 2; i * j <= 4000000; j++) {
				sieve[j * i] = true;
			}
		}
	}
	for(i = 2; i <= 4000000; i++) {
		if(!sieve[i])
			prime.push_back(i);
	}
	
	cin >> N;
	ans = 0, sum = 2, l = 0, r = 0;
	while(r < prime.size() && prime[r] <= N) {
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