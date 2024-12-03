#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int A, B, cnt = 0, i;
	vector<int> N;
	
	cin >> A >> B;
	A += B;
	N.resize(A);
	for(auto& e : N)
		cin >> e;
	sort(N.begin(), N.end());
	for(i = 1; i < A; i++) {
		if(N[i] == N[i - 1])
			cnt++;
	}
	cout << A - 2*cnt;
	
	return 0;
}