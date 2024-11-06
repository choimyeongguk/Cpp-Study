#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> tri;

void solve(int r, int c, int n) {
	if(n == 3) {
		tri[r][c] = '*';
		tri[r + 1][c - 1] = tri[r + 1][c + 1] = '*';
		tri[r + 2][c - 2] = tri[r + 2][c - 1] = tri[r + 2][c] = tri[r + 2][c + 1] = tri[r + 2][c + 2] = '*';
		return;
	}
	n /= 2;
	solve(r, c, n);
	solve(r + n, c - n, n);
	solve(r + n, c + n, n);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	tri.assign(N + 1, vector<char>(2 * N, ' '));
	solve(1, N, N);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= 2 * N - 1; j++) {
			cout << tri[i][j];
		}
		cout << "\n";
	}
	
	return 0;
}