#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T, n, m, i, j;
	long long ans;
	int A[1001], B[1001];
	unordered_map<int,long long> sumA;
	
	cin >> T >> n;
	A[0] = 0;
	for(i = 1; i <= n; i++) {
		cin >> A[i];
		A[i] += A[i - 1];
	}
	for(i = 0; i <= n; i++) {
		for(j = i + 1; j <= n; j++) {
			sumA[A[j] - A[i]]++;
		}
	}
	cin >> m;
	B[0] = 0;
	for(i = 1; i <= m; i++) {
		cin >> B[i];
		B[i] += B[i - 1];
	}
	
	for(ans = 0, i = 1; i <= m; i++) {
		for(j = i - 1; j >= 0; j--) {
			if(sumA.count(T - B[i] + B[j]))
				ans += sumA[T - B[i] + B[j]];
		}
	}
	cout << ans;
	
	return 0;
}