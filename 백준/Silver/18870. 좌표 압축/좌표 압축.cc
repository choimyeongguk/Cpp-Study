#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, idx, prev, i;
	vector<pair<int,int>> X;  // 값, 입력 순서 
	vector<int> X_compressed;
	
	cin >> N;
	X.resize(N);
	for(i = 0; i < N; i++) {
		cin >> X[i].first;
		X[i].second = i;
	}
	sort(X.begin(), X.end());
	
	X_compressed.resize(N);
	idx = 0;
	prev = X[0].first;
	X_compressed[X[0].second] = idx;
	for(i = 1; i < N; i++) {
		if(X[i].first != prev) {
			prev = X[i].first;
			idx++;
		}
		X_compressed[X[i].second] = idx;
	}
	
	for(auto& e : X_compressed) {
		cout << e << " ";
	}
	
	return 0;
}