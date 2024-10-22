#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, i;
	vector<int> X;
	priority_queue<int, vector<int>, greater<int>> X_sorted;
	vector<int> map;
	
	cin >> N;
	X.assign(N, 0);
	for(auto& e : X) {
		cin >> e;
		X_sorted.push(e);
	}
	
	map.push_back(X_sorted.top());
	X_sorted.pop();
	while(!X_sorted.empty()) {
		if(map.back() != X_sorted.top()) {
			map.push_back(X_sorted.top());
		}
		X_sorted.pop();
	}
	
	for(auto& e : X) {
		cout << lower_bound(map.begin(), map.end(), e) - map.begin() << " ";
	}
	
	
	return 0;
} 