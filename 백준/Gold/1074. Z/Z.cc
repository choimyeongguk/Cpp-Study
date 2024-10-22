#include <bits/stdc++.h>
using namespace std;

int r, c;

int dfs(int R, int C, int size) {
	if(R == r && C == c) {
		return 0;
	}
	int ans = 0, n = size / 2;
	if     (r < R + n && c < C + n)	 ans += dfs(R, C, n);
	else if(r < R + n && c >= C + n) ans += n * n + dfs(R, C + n, n);
	else if(r >= R + n && c < C + n) ans += n * n * 2 + dfs(R + n, C, n);
	else							 ans += n * n * 3 + dfs(R + n, C + n, n);
	
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	
	cin >> N >> r >> c;
	cout << dfs(0, 0, pow(2, N));
	
	return 0;
}