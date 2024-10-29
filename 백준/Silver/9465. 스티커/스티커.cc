#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	vector<vector<int>> sticker;
	
	cin >> n;
	
	sticker.resize(2, vector<int>(n));
	for(auto& r : sticker) {
		for(auto& c : r) {
			cin >> c;
		}
	}
	sticker[0][1] += sticker[1][0];
	sticker[1][1] += sticker[0][0];
	for(int i = 2; i < n; i++) {
		sticker[0][i] += max(sticker[1][i - 1], sticker[1][i - 2]);
		sticker[1][i] += max(sticker[0][i - 1], sticker[0][i - 2]);
	}
	cout << max(sticker[0][n - 1], sticker[1][n - 1]) << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	for(cin >> T; T--;) {
		solve();
	}
	
	return 0;
} 