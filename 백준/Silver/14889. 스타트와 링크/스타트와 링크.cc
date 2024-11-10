#include <bits/stdc++.h>
using namespace std;

int N, ans = 0x3f3f3f3f;
int M[21][21];
vector<int> team0, team1;

void solve(int depth) {
	if(depth == N) {
		if(team0.size() != N / 2) return;
		int team[2] = { 0 };
		for(int i = 0; i < N / 2; i++)
			for(int j = 0; j < N / 2; j++) {
				team[0] += M[team0[i]][team0[j]];
				team[1] += M[team1[i]][team1[j]];
			}
		ans = min(ans, abs(team[0] - team[1]));
		return;
	}
	
	team0.push_back(depth);
	solve(depth + 1);
	team0.pop_back();
	
	team1.push_back(depth);
	solve(depth + 1);
	team1.pop_back();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> M[i][j];
	solve(0);
	cout << ans;
	
	return 0;
}