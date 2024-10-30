#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	bool chk = false;
	int A, B, cnt = 0;
	cin >> A >> B;
	while(A < B) {
		if(B % 2 == 0) {
			B /= 2;
		} else if(B % 10 == 1) {
			B /= 10;
		} else break;
		cnt++;
		if(A == B) chk = true;
	}
	if(chk) cout << cnt + 1;
	else cout << -1;
	
	return 0;
}