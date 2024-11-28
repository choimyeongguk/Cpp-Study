#include <bits/stdc++.h>
using namespace std;

bool broken[10] = { 0 };

int digit(int x) {
	int ret = 0;
	do {
		ret++;
		x /= 10;
	} while(x);
	return ret;
}

bool canMake(int x) {
	do {
		if(broken[x % 10])
			return false;
		x /= 10;
	} while(x);
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, ans, tmp, i;
	
	cin >> N >> M;
	for(i = 0; i < M; i++) {
		cin >> tmp;
		broken[tmp] = true;
	}
	
	ans = abs(N - 100);
	for(i = N; i >= 0; i--) {
		if(canMake(i)) {
			ans = min(ans, digit(i) + N - i);
			break;
		}
	}
	for(i = N; i <= 900000; i++) {
		if(canMake(i)) {
			ans = min(ans, digit(i) + i - N);
			break;
		}
	}
	cout << ans;
	
	return 0;
}