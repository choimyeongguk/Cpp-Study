#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, l, r, tmp, ans = 0, i;
	int A[10001] = { 0 };
	
	cin >> N >> M;
	for(i = 1; i <= N; i++) {
		cin >> A[i];
		A[i] += A[i - 1];
	}
	for(i = 1; i <= N; i++) {
		if(binary_search(A, A + i, A[i] - M))
			ans++;
	}
	cout << ans;
	
	return 0;
}