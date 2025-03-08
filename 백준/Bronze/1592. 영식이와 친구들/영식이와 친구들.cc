#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, L, ball = 1, ans = 0;
	int cnt[51] = { 0 };
	
	cin >> N >> M >> L;
	cnt[1] = 1;
	while(true) {
		if(cnt[ball] == M) break;
		if(cnt[ball] % 2) {	// 홀수 
			ball += L;
			if(ball > N) ball -= N;
		}
		else {				// 짝수 
			ball -= L;
			if(ball < 1) ball += N;
		}
		ans++;
		cnt[ball]++;
	}
	cout << ans;
	
	return 0;
}