#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, max, ans, end, i, j;
	vector<pair<int,int>> meeting;
	
	cin >> N;
	
	meeting.resize(N);
	for(auto& e : meeting) {
		cin >> e.first >> e.second;
	}
	sort(meeting.begin(), meeting.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
		if(a.second == b.second) {
			return a.first < b.first;
		}
		return a.second < b.second;
	});
	
	ans = 1;
	end = meeting[0].second;
	for(i = 1; i < N; i++) {
		if(meeting[i].first < end) continue;
		end = meeting[i].second;
		ans++;
	}
	
	cout << ans;
	
	return 0;
}