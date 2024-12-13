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
		for(j = i - 1; j >= 0; j--) {
			sumA[A[i] - A[j]]++;
		}
	}
	cin >> m;
	B[0] = 0;
	for(i = 1; i <= m; i++) {
		cin >> B[i];
		B[i] += B[i - 1];
	}
	
	ans = 0;
	for(i = 1; i <= m; i++) {
		for(j = i - 1; j >= 0; j--) {
			auto it = sumA.find(T - (B[i] - B[j]));
			if(it != sumA.end())
				ans += it->second;
		}
	}
	cout << ans;
	
	return 0;
}