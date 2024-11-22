#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, S, ans = 0, i, j;
	int seq[100001] = { 0 };
	
	cin >> N >> S;
	for(i = 1; i <= N; i++) {
		cin >> seq[i];
		seq[i] += seq[i - 1];
	}
	for(i = 1; seq[i] < S && i <= N; i++);
	for(ans = i; i <= N; i++) {
		for(j = i - ans; seq[i] - seq[j] >= S && j <= i; j++);
		j--;
		if(ans > i - j)
			ans = i - j;
	}
	cout << (ans == N + 1 ? 0 : ans);
	
	return 0;
}