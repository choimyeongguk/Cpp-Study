#include <bits/stdc++.h>
#define INF 987654321
#define pii pair<int,int>
using namespace std;

int main() {
	int N, M, s, e, c, i;
	int curNode, curDist, nxtNode, nxtDist;
	vector<int> distance;
	vector<vector<pii>> cost;
	priority_queue<pii, vector<pii>, greater<pii>> heap;	// 거리, 노드. 거리에 따라 우선순위 결정 
	
	cin >> N >> M;
	distance.assign(N, INF);
	cost.assign(N, vector<pii>());
	for(i = 0; i < M; i++) {
		cin >> s >> e >> c;
		s--; e--;
		cost[s].push_back({e, c});		// 단방향 간선 추가 
	}
	cin >> s >> e;
	s--; e--;
	
	// 다익스트라 알고리즘
	distance[s] = 0;
	heap.push({0, s});
	while(!heap.empty()) {
		curDist = heap.top().first;
		curNode = heap.top().second;
		heap.pop();
		
		if(curDist > distance[curNode]) {
			continue;
		}
		
		for(i = 0; i < cost[curNode].size(); i++) {		// 현재 노드에서 출발하는 간선들 
			nxtNode = cost[curNode][i].first;
			nxtDist = curDist + cost[curNode][i].second;
			
			if(distance[nxtNode] > nxtDist) {
				distance[nxtNode] = nxtDist;
				heap.push({nxtDist, nxtNode});
			}
		}
	}
	cout << distance[e];
	
	return 0;
}