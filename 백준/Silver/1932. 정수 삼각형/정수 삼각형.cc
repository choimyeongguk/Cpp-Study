#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, max, i, j;
	cin >> N;
	vector<vector<int>> tri(N, vector<int>(N, 0));
	
	cin >> tri[0][0];
	for(i = 1; i < N; i++) {
		for(j = 0; j <= i; j++) {
			cin >> tri[i][j];
			max = j > 0 ? tri[i - 1][j - 1] : 0;
			max = max > tri[i - 1][j] ? max : tri[i - 1][j];
			tri[i][j] += max;
		}
	}
	for(max = 0, i = 0; i < N; i++) {
		max = max > tri[N - 1][i] ? max : tri[N - 1][i];
	}
	cout << max << "\n";
	
	return 0;
}