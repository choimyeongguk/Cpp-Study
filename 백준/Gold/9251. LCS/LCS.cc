#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	bool chk;
	int tmp, ans, i, j;
	int N[1000] = { 0 };
	string A, B;
	
	cin >> A >> B;

	for(i = 0; i < B.length(); i++) {
		for(tmp = 0, j = 0; j < A.length(); j++) {
			chk = false;
			if(A[j] == B[i]) {
				if(tmp + 1 > N[j]) {
					N[j] = tmp + 1;
					chk = true;
				}
			}
			if(tmp < N[j]) {
				if(A[j] == B[i] && chk) continue;
				tmp = N[j];
			}
		}
	}
	for(ans = 0, i = 0; i < A.length(); i++) {
		if(ans < N[i]) ans = N[i];
	}
	cout << ans;

	return 0;
}