#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int M, N, i, j;
	bool isPrime;
	
	cin >> M >> N;
	if(M == 1) M++;
	if(N == 1) return 0;
	
	for(i = M; i <= N; i++) {
		isPrime = true;
		for(j = 2; j*j <= i; j++) {
			if(!(i % j)) {
				isPrime = false;
				break;
			}
		}
		if(isPrime) cout << i << '\n';
	}
	
	return 0;
}