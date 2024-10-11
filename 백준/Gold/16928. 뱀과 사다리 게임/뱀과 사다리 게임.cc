#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, a, b, node, num, nxtNode, i;
	int move[101];
	bool visited[101] = { 0 };
	queue<pair<int,int>> bfs;
	
	cin >> N >> M;
	for(i = 0; i < 101; i++) {
		move[i] = i;
	}
	for(i = 0, N += M; i < N; i++) {
		cin >> a >> b;
		move[a] = b;
	}
	
	bfs.push({1, 0});
	visited[1] = true;
	while((node = bfs.front().first) != 100) {
		num = bfs.front().second + 1;
		bfs.pop();
		
		for(i = 1; i <= 6; i++) {
			nxtNode = node + i;
			if(nxtNode > 100) continue;
			nxtNode = move[nxtNode];
			if(!visited[nxtNode]) {
				bfs.push({nxtNode, num});
				visited[nxtNode] = true;
			}
		}
	}
	cout << bfs.front().second;
	
	return 0;
}