#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
	if(a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, x, y, i;
	vector<pair<int, int>> coordinate;
	
	cin >> N;
	coordinate.assign(N, pair<int, int>());
	for(i = 0; i < N; i++) {
		cin >> x >> y;
		coordinate[i] = { x, y };
	}
	sort(coordinate.begin(), coordinate.end(), compare);
	for(i = 0; i < N; i++) {
		cout << coordinate[i].first << ' ' << coordinate[i].second << '\n';
	}
	
	return 0;
}