#include <bits/stdc++.h>
using namespace std;

int getComb(int n, int k) {
	int result = 1;
	for(int i = n; i > k; i--) {
		result *= i;
	}
	for(int i = n-k; i > 0; i--) {
		result /= i;
	}
	return result;
}

int main() {
	int N, K;
	
	cin >> N >> K;
	cout << getComb(N, K);
	
	return 0;
}