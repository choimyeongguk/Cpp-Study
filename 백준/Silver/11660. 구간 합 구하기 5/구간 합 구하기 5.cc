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
			table[i][j] += table[i][j - 1] + table[i - 1][j] - table[i - 1][j - 1];
		}
	}
	for(i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << table[x2][y2] - table[x2][y1 - 1] - table[x1 - 1][y2] + table[x1 - 1][y1 - 1] << "\n";
	}
	
	return 0;
}