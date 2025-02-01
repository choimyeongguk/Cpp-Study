#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, K, tmp, i;
	int last, max, idx;
	int arr[10000];
	
	cin >> N >> K;
	for(i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	last = N - 1;
	while(K) {
		max = arr[0], idx = 0;
		for(i = 1; i <= last; i++) {
			if(max < arr[i]) {
				max = arr[i];
				idx = i;
			}
		}
		
		if(idx != last) {
			K--;
			tmp = arr[idx];
			arr[idx] = arr[last];
			arr[last] = tmp;
		}		
		else if(idx == 0){
			cout << -1;
			return 0;
		}
		last--;
	}
	
	for(i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	
	return 0;
}