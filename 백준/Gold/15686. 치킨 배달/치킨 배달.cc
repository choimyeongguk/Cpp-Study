#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int city[50][50];
int N, M, ans = INF;
vector<int> idx;
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;

void getDist() {
	int dist = 0, min, l;
	for(auto& h : house) {
		min = INF;
		for(auto& i : idx) {
			l = abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second);
			min = min < l ? min : l;
		}
		dist += min;
	}
	ans = ans < dist ? ans : dist;
}

void comb(int start, int depth) {
	if(depth++ == M) {
		getDist();
		return;
	}
	for(int i = start; i < chicken.size(); i++) {
		idx.push_back(i);
		comb(i + 1, depth);
		idx.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> city[i][j];
			if(city[i][j] == 2)
				chicken.push_back({i, j});
			else if(city[i][j] == 1)
				house.push_back({i, j});
		}
	}

	comb(0, 0);
	cout << ans;
	
	return 0;
}