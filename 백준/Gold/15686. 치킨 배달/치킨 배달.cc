#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int city[50][50];
int N, M, ans = INF;
vector<pair<int,int>> choose;
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;

void getDist() {
	int dist = 0, min, l;
	for(auto& h : house) {
		min = INF;
		for(auto& ch : choose) {
			l = abs(ch.first - h.first) + abs(ch.second - h.second);
			min = min < l ? min : l;
		}
		dist += min;
	}
	ans = ans < dist ? ans : dist;
}

void comb(int start, int depth) {
	if(depth == M) {
		getDist();
		return;
	}
	for(int i = start; i < chicken.size(); i++) {
		choose.push_back(chicken[i]);
		comb(i + 1, depth + 1);
		choose.pop_back();
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