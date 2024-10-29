#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, K, t, x;
	vector<bool> visited;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> bfs;  // 시간, 위치 
	
	cin >> N >> K;
	
	visited.assign(200001, false);
	visited[N] = true;
	bfs.push({0, N});
	while(bfs.top().second != K) {
		t = bfs.top().first;
		x = bfs.top().second;
		bfs.pop();
		
		if(x > 0 && !visited[x - 1]){
			bfs.push({ t + 1, x - 1 });
			visited[x - 1] = true;
		}
		if(x > K) continue;
		if(x && 3 * x < 2 * K && !visited[x * 2]){
			bfs.push({t, x * 2});
			visited[x * 2] = true;
		}
		if(!visited[x + 1]){
			bfs.push({t + 1, x + 1});
			visited[x + 1] = true;
		}
	}
	cout << bfs.top().first;
	
	return 0;
}