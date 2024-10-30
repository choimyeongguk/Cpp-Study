#include <bits/stdc++.h>
using namespace std;

int N, M;
string ans;
vector<bool> used;

void comb() {
	if(ans.length() == M * 2) {
		cout << ans;
		cout << "\n";
		return;
	}
	for(int i = 1; i <= N; i++) {
		if(used[i]) continue;
		ans += i + '0';
		ans += ' ';
		used[i] = true;
		comb();
		ans.pop_back();
		ans.pop_back();
		used[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	used.assign(N + 1, false);
	comb();
	return 0;
}