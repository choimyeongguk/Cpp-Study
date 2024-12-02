#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, cnt = 0, nxt, i, j;
	int stream[100001];
	int in_degree[100001] = { 0 };
	queue<int> q;
	
	cin >> n;
	for(i = 1; i <= n; i++) {
		cin >> j;
		stream[i] = j;
		in_degree[j]++;
	}
	for(i = 1; i <= n; i++) {
		if(!in_degree[i]) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		cnt++;
		nxt = stream[q.front()];
		in_degree[nxt]--;
		if(!in_degree[nxt]) {
			q.push(nxt);
		}
		q.pop();
	}
	cout << cnt << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	while(T--)
		solve();
	
	return 0;
}