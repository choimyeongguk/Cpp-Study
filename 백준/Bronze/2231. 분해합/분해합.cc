#include <bits/stdc++.h>
using namespace std;

int getDSum(int x) {
	int result = x;
	while(x > 0) {
		result += x % 10;
		x /= 10;
	}
	return result;
}

int main() {
	int N, M = 0;
	
	cin >> N;
	for(int i = 1; i <= N; i++) {
		if(getDSum(i) == N) {
			M = i;
			break;
		}
	}
	cout << M;
	
	return 0;
}