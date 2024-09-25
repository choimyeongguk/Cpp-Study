#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, x, y, i;
	vector<pair<int, int>> loc;
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> x >> y;
		loc.push_back({x, y});
	}
	sort(loc.begin(), loc.end(), [](auto& a, auto& b) {
		if(a.first == b.first) {
			return a.second < b.second;
		}
		return a.first < b.first;
	});
	for(auto& e : loc) {
		cout << e.first << ' ' << e.second << '\n';
	}
	
	return 0;
}