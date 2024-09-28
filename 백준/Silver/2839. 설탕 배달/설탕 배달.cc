#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, cnt = 0;
	
	cin >> N;
	while(N % 5 > 0) {
		cnt++;
		N -= 3;
	}
	if(N < 0) {
		cnt = -1;
	}
	cnt += N / 5;
	cout << cnt;
	
	return 0;
}