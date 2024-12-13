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
	for(i = 0; i < n; i++)
		cin >> A[i];
	cin >> m;
	for(i = 0; i < m; i++)
		cin >> B[i];
		
	for(i = 0; i < n; i++) {
		for(sum = 0, j = i; j < n; j++) {
			sum += A[j];
			sumA[sum]++;
		}
	}
	for(i = 0; i < m; i++) {
		for(sum = 0, j = i; j < m; j++) {
			sum += B[j];
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