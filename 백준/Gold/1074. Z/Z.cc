#include <bits/stdc++.h>
using namespace std;

int r, c;

int dfs(int R, int C, int N) {
	if(R == r && C == c) {
		return 0;
	}
	int ans = 0, n = pow(2, N - 1);
	if     (r < R + n && c < C + n)	 ans += dfs(R, C, N - 1);
	else if(r < R + n && c >= C + n) ans += n * n + dfs(R, C + n, N - 1);
	else if(r >= R + n && c < C + n) ans += n * n * 2 + dfs(R + n, C, N - 1);
	else							 ans += n * n * 3 + dfs(R + n, C + n, N - 1);
	
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	
	cin >> N >> r >> c;
	cout << dfs(0, 0, N);
	
	return 0;
}