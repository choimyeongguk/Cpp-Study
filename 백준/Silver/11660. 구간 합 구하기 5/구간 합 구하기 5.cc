#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, x1, y1, x2, y2, ans, i, j;
	vector<vector<int>> table;
	
	cin >> N >> M;
	table.assign(N + 1, vector<int>(N + 1, 0));
	for(i = 1; i <= N; i++) {
		for(j = 1; j <= N; j++) {
			cin >> table[i][j];
			table[i][j] += table[i][j - 1];
		}
	}
	for(i = 0; i < M; i++) {
		cin >> y1 >> x1 >> y2 >> x2;
		ans = 0;
		for(j = y1; j <= y2; j++) {
			ans += table[j][x2] - table[j][x1 - 1];
		}
		cout << ans << "\n";
	}
	
	return 0;
}