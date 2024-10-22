#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, idx, prev, i;
	vector<pair<int,int>> X;  // 값, 입력 순서 
	
	cin >> N;
	X.resize(N);
	for(i = 0; i < N; i++) {
		cin >> X[i].first;
		X[i].second = i;
	}
	sort(X.begin(), X.end());
	
	idx = 0;
	prev = X[0].first;
	X[0].first = idx;
	for(i = 1; i < N; i++) {
		if(X[i].first == prev) {
			X[i].first = idx;
		} else {
			prev = X[i].first;
			X[i].first = ++idx; 
		}
	}
	
	sort(X.begin(), X.end(), [](const pair<int,int> a, const pair<int,int> b) {
		return a.second < b.second;
	});
	for(auto& e : X) {
		cout << e.first << " ";
	}
	
	return 0;
}