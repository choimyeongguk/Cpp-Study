#include <bits/stdc++.h>
using namespace std;

int N, S, L, ans = 0;
int seq[20];

void solve(int start, int val, int depth) {
	if(depth == L) {
		if(val == S) ans++;
		return;
	}
	for(int i = start; i < N; i++) {
		solve(i + 1, val + seq[i], depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> S;
	for(int i = 0; i < N; i++) {
		cin >> seq[i];
	}
	
	for(L = 1; L <= N; L++) {
		solve(0, 0, 0);
	}
	cout << ans;
	
	return 0;
}