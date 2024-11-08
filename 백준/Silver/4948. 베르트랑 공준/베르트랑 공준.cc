#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int isPrime[246913];
	int n, i, j;
	
	fill(isPrime, isPrime + 246913, 1);
	isPrime[0] = isPrime[1] = 0;
	for(i = 2; i <= 246912; i++) {
		if(isPrime[i]) {
			for(j = 2; i * j <= 246912; j++) {
				isPrime[i * j] = 0;
			}
		}
	}
	for(i = 3; i <= 246912; i++) {
		isPrime[i] += isPrime[i - 1];
	}
	while(true) {
		cin >> n;
		if(!n) break;
		cout << isPrime[2 * n] - isPrime[n] << "\n";
	}
	
	
	return 0;
}