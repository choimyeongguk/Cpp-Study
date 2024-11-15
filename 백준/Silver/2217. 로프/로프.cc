#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, ans = 0, i;
	int rope[100000];
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> rope[i];
	}
	sort(rope, rope + i);
	for(i = 0; i < N; i++) {
		ans = max(ans, rope[i] * (N - i));
	}
	cout << ans;
	
	return 0;
}