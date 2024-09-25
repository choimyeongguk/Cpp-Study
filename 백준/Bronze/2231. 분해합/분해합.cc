#include <bits/stdc++.h>
using namespace std;

int getDigit(int x) {
	int n = 0;
	while(x > 0) {
		n++;
		x /= 10;
	}
	return n;
}

int getDSum(int x) {
	int result = x;
	while(x > 0) {
		result += x % 10;
		x /= 10;
	}
	return result;
}

int main() {
	int N, M = 0, upperLimit;
	
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