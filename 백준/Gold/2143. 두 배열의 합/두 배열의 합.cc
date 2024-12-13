#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T, n, m, sum, i, j;
	long long ans;
	int A[1001], B[1001];
	unordered_map<int,long long> sumA, sumB;
	
	cin >> T >> n;
	A[0] = 0;
	for(i = 1; i <= n; i++) {
		cin >> A[i];
		A[i] += A[i - 1];
	}
	cin >> m;
	B[0] = 0;
	for(i = 1; i <= m; i++) {
		cin >> B[i];
		B[i] += B[i - 1];
	}
		
	for(i = 0; i <= n; i++) {
		for(j = i + 1; j <= n; j++) {
			sum = A[j] - A[i];
			sumA[sum]++;
		}
	}
	for(i = 0; i <= m; i++) {
		for(j = i + 1; j <= m; j++) {
			sum = B[j] - B[i];
			sumB[sum]++;
		}
	}
	
	ans = 0;
	for(auto& e : sumA) {
		auto it = sumB.find(T - e.first);
		if(it != sumB.end()) {
			ans += e.second * it->second;
		}
	}
	cout << ans;
	
	return 0;
}