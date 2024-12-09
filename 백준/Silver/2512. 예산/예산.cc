#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, min, mid, max, sum, ans, i;
	int req[10001];
	
	cin >> N;
	for(max = 0, i = 0; i < N; i++) {
		cin >> req[i];
		max = max > req[i] ? max : req[i];
	}
	sort(req, req + N);
	cin >> M;
	
	ans = min = 0;
	while(min <= max) {
		mid = (min + max) / 2;
		for(sum = 0, i = 0; req[i] <= mid && i < N; i++) {
			sum += req[i];
		}
		for(; i < N; i++) {
			sum += mid;
		}
		
		if(sum <= M) {
			ans = ans > mid ? ans : mid;
			min = mid + 1;
		}
		else{
			max = mid - 1;
		}
	}
	
	cout << ans;
	
	return 0;
}