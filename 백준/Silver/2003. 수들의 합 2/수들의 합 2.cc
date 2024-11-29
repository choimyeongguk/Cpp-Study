#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, ans, tmp, i, j;
	int A[10001] = { 0 };
	
	cin >> N >> M;
	for(i = 1; i <= N; i++) {
		cin >> A[i];
		A[i] += A[i - 1];
	}
	for(ans = 0, i = 1; i <= N; i++) {
		for(j = i - 1; j >= 0; j--) {
			tmp = A[i] - A[j];
			if(tmp == M) {
				ans++;
				break;
			}
			else if(tmp > M)
				break;
		}
	}
	
	cout << ans;
	
	return 0;
}