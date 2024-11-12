#include <bits/stdc++.h>
using namespace std;

int N, S, ans = 0;
int seq[20];

void solve(int val, int depth) {
	if(depth == N) {
		if(val == S) ans++;
		return;
	}
	solve(val + seq[depth++], depth);
	solve(val, depth);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> S;
	for(int i = 0; i < N; i++) {
		cin >> seq[i];
	}
	solve(0, 0);
	cout << (S ? ans : ans - 1);
	
	return 0;
}