#include <bits/stdc++.h>
using namespace std;

int isPrime(int x) {
	if(x == 1) return 0;
	for(int i = 2; i <= sqrt(x); i++) {
		if(x%i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int N, num, cnt = 0;
	
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> num;
		cnt += isPrime(num);
	}
	cout << cnt;
	
	return 0;
}