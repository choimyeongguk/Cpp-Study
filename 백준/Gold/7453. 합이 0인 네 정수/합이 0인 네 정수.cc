#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, i, j;
	long long ans;
	int A[4000], B[4000], C[4000], D[4000];
	vector<int> ApB, CpD;
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			ApB.push_back(A[i] + B[j]);
		}
	}
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			CpD.push_back(C[i] + D[j]);
		}
	}
	sort(ApB.begin(), ApB.end());
	sort(CpD.begin(), CpD.end());
	
	ans = 0;
	for(auto& e : ApB) {
		ans += upper_bound(CpD.begin(), CpD.end(), -e) - lower_bound(CpD.begin(), CpD.end(), -e);
	}
	cout << ans;
	
	return 0;
}