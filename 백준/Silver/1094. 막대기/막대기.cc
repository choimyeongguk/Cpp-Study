#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, cnt = 0;
	
	cin >> N;
	while(N) {
		cnt += N & 1;
		N >>= 1;
	}
	cout << cnt;
	
	return 0;
}