#include <bits/stdc++.h>
using namespace std;

int N, ans = 0;
vector<int> chess;
vector<bool> used;

void comb(int depth) {
	if(depth++ == N) {
		ans++;
		return;
	}
	int i, j, chk;
	for(i = 0; i < N; i++) {
		if(used[i]) continue;
		for(chk = 0, j = 0; j < chess.size(); j++) {
			if(abs(chess[j] - i) == chess.size() - j) {
				chk = true;
				break;
			}
		}
		if(chk) continue;
		
		used[i] = true;
		chess.push_back(i);
		comb(depth);
		chess.pop_back();
		used[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	used.assign(N, false);
	comb(0);
	cout << ans;
	
	return 0;
}