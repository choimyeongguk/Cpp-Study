#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, ans, sum, l, r, i;
	int seq[100000];
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> seq[i];
	}
	sort(seq, seq + N);
	cin >> M;
	
	ans = 0, l = 0, r = N - 1;
	while(l < r) {
		sum = seq[l] + seq[r];
		if(sum < M) {
			l++;
		}
		else if(sum > M) {
			r--;
		}
		else {
			ans++;
			l++;
		}
	}
	cout << ans;
	
	return 0;
}