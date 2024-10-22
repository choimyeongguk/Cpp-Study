#include <bits/stdc++.h>
using namespace std;

int r, c;

int dfs(int size) {
	if(size == 1) {
		return 0;
	}
	int ans = 0, n = size / 2;
	if(r >= n && c >= n) {
		c -= n; r -= n;
		ans += n * n * 3;
	} else if(r >= n) {
		r -= n;
		ans += n * n * 2;
	} else if(c >= n) {
		c -= n;
		ans += n * n;
	}
	ans += dfs(n);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	
	cin >> N >> r >> c;
	cout << dfs(pow(2, N));
	
	return 0;
}