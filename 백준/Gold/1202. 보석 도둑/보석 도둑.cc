#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long ans;
	int N, K, idx, i;
	int C[300000];
	pair<int,int> gem[300000];
	priority_queue<int, vector<int>> pq;
	
	cin >> N >> K;
	for(i = 0; i < N; i++)
		cin >> gem[i].first >> gem[i].second;
	sort(gem, gem + N);
	for(i = 0; i < K; i++)
		cin >> C[i];
	sort(C, C + K);
	
	for(ans = 0, idx = 0, i = 0; i < K; i++) {
		while(idx < N && gem[idx].first <= C[i]) {
			pq.push(gem[idx++].second);
		}
		if(pq.empty()) continue;
		ans += pq.top();
		pq.pop();
	}
	cout << ans;
	
	return 0;
}