#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, lemon, ans = 0, i;
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> lemon;
		ans = max(ans, lemon - N + i);
	}
	cout << ans;
	
	return 0;
}