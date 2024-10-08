#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, cnt = 1, max = 1, i, j;
	double x, y;
	vector<pair<int, int>> S;
	vector<pair<double, double>> pSet;
	
	cin >> n;
	S.assign(n, pair<int, int>());
	for(i = 0; i < n; i++) {
		cin >> x >> y;
		S[i] = { x, y };
	}
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			x = (S[i].first + S[j].first) / 2.0;
			y = (S[i].second + S[j].second) / 2.0;
			pSet.push_back({ x, y });
		}
	}
	sort(pSet.begin(), pSet.end());
	
	for(i = 1; i < pSet.size(); i++) {
		if(pSet[i] == pSet[i-1]) {
			cnt++;
			if(cnt > max) max = cnt;
		} else {
			cnt = 1;
		}
	}
	
	cout << max;
	
	return 0;
}