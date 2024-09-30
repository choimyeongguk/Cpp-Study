#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int K, N, l, max, cnt, i;
	long long int start, mid, end, result;
	int cable[10001];
	
	cin >> K >> N;
	for(i = 0, max = 0; i < K; i++) {
		cin >> l;
		cable[i] = l;
		max = max > l ? max : l;
	}
	
	start = 1; end = max;
	while(start <= end) {
		mid = (start + end) / 2;
		for(i = 0, cnt = 0; i < K; i++) {
			cnt += cable[i] / mid;
		}
		if(cnt < N) {
			end = mid - 1;
		} else {
			result = mid;
			start = mid + 1;
		}
	}
	cout << result;
	
	return 0;
}