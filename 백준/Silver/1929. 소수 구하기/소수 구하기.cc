#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int M, N, i, j;
	bool prime[1000001];
	
	cin >> M >> N;
	
	fill(prime, prime + N + 1, true);
	prime[1] = false;
	for(i = 2; i < N; i++) {
		if(!prime[i]) continue;
		for(j = 2; i*j <= N; j++) {
			prime[i*j] = false;
		}
	}
	for(i = M; i <= N; i++) {
		if(prime[i]) cout << i << '\n';
	}
	
	return 0;
}