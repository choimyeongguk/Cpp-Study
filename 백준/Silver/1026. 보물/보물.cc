#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, ans = 0, i;
	int A[50], B[50];
	
	cin >> N;
	for(i = 0; i < N; i++) cin >> A[i];
	for(i = 0; i < N; i++) cin >> B[i];
	sort(A, A + N);
	sort(B, B + N, greater<int>());
	for(i = 0; i < N; i++) ans += A[i] * B[i];
	cout << ans;
	
	return 0;
} 