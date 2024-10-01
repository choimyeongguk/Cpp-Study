#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T, N, i;
	vector<pair<int, int>> call(41);
	
	call[0] = { 1, 0 }; call[1] = { 0, 1 };	
	for(i = 2; i <= 40; i++) {
		call[i] = { call[i-1].first + call[i-2].first, call[i-1].second + call[i-2].second };
	}
	
	cin >> T;
	for(i = 0; i < T; i++) {
		cin >> N;
		cout << call[N].first << ' ' << call[N].second << '\n';
 	}
	
	return 0;
}