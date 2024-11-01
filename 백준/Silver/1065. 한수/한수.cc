#include <bits/stdc++.h>
using namespace std;

bool isHansu(int x) {
	int prev = x % 10;
	x /= 10;
	int d = x % 10  - prev;
	prev = x % 10;
	x /= 10;
	while(x) {
		if(x % 10 - prev != d) return false;
		x /= 10;
	}
	return true;
}

int main() {
	int N, ans = 0;
	cin >> N;
	for(int i = 1; i <= N; i++) {
		if(isHansu(i)) ans++;
	}
	cout << ans;
}