#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, ans, i;
	int A[1000];
	int asc[1000], desc[1000];
	vector<int> L;
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> A[i];
	}
	for(i = 0; i < N; i++) {
		auto it = lower_bound(L.begin(), L.end(), A[i]);
		if(it == L.end()) {
			L.push_back(A[i]);
			asc[i] = L.size();
		} else {
			*it = A[i];
			asc[i] = it - L.begin() + 1;
		}
	}
	L.clear();
	for(i = N - 1; i >= 0; i--) {
		auto it = lower_bound(L.begin(), L.end(), A[i]);
		if(it == L.end()) {
			L.push_back(A[i]);
			desc[i] = L.size();
		} else {
			*it = A[i];
			desc[i] = it - L.begin() + 1;
		}
	}
	
	for(ans = 0, i = 0; i < N; i++) {
		ans = max(ans, asc[i] + desc[i] - 1);
	}
	cout << ans;
	
	return 0;
}