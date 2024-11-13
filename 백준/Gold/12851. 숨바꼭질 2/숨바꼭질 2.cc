#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, K, min = INF, cnt = 0, n, t;
	queue<pair<int,int>> q;  // node, time
	vector<pair<int,int>> visited;  // time, cnt
	
	cin >> N >> K;
	visited.assign(200001, pair<int,int>({INF, 0}));
	q.push({N, 0});
	while(!q.empty()) {
		n = q.front().first;
		t = q.front().second;
		q.pop();
		
		if(t > min) continue;
		if(visited[n].first > t) {
			visited[n] = { t, 1 };
		} else if(visited[n].first == t) {
			visited[n].second++;
		} else continue;

		if(n > 0) q.push({ n - 1, t + 1 });
		if(n > K) continue;
		if(n && 3 * n < 2 * K) q.push({ n * 2, t + 1 });
		q.push({ n + 1, t + 1 });
	}
	
	cout << visited[K].first << "\n" << visited[K].second;
	
	return 0;
}