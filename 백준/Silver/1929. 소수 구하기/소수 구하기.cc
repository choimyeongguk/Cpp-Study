#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int M, N, i, j;
	bool chk;
	vector<int> prime;
	
	cin >> M >> N;
	if(M == 1) M++;
	if(N == 1) return 0;
	
	prime.push_back(2);
	for(i = 3; i < M; i++) {
		chk = true;
		for(j = 0; prime[j]*prime[j] <= i; j++) {
			if(!(i % prime[j])) chk = false;
		}
		if(chk) prime.push_back(i);
	}
	for(i = M; i <= N; i++) {
		chk = true;
		for(j = 0; prime[j]*prime[j] <= i; j++) {
			if(!(i % prime[j])) chk = false;
		}
		if(chk) {
			prime.push_back(i);
			cout << i << '\n';	
		}	
	}
	
	return 0;
}