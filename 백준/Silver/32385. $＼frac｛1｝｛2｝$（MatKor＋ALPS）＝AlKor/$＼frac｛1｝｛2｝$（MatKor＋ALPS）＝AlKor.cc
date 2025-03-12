#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, tmp, i;
	
	cin >> N;
	if(N % 2 == 0) {
		for(i = 0; i < N; i++) {
			cout << 1 + 2 * i << " ";
		}
		cout << N;
	}
	else {
		tmp = 0;
		for(i = 1; i < N; i++) {
			cout << i << " ";
			tmp += i;
		}
		for(i = 1000000000; (i + tmp) % N != 0; i--);
		cout << i << " " << (i + tmp) / N;
	}
	
	return 0;
}