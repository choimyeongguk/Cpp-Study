#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, K, ans;
	queue<pair<int,int>> bfs;
	bool visited[200000] = { 0 };
	
	cin >> N >> K;
	bfs.push({N, 0});
	while(true) {
		int& loc = bfs.front().first;
		int& cnt = bfs.front().second;
		if(loc == K) {
			ans = cnt;
			break;
		}
		if(loc < K) {
			if(!visited[loc * 2]) {
				bfs.push({loc * 2, cnt + 1});
				visited[loc * 2] = true;
			}
			if(!visited[loc + 1]) {
				bfs.push({loc + 1, cnt + 1});
				visited[loc + 1] = true;
			}
		}
		if(loc > 0 && !visited[loc - 1]) {
			bfs.push({loc - 1, cnt + 1});
			visited[loc - 1] = true;
		}
		bfs.pop();
	}
	cout << ans;
	
	return 0;
}