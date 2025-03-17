#include <bits/stdc++.h>
using namespace std;

int main() {
	int i, l, r, j;
	string S, ans = "";
	
	cin >> S;
	for(i = 0; i < S.length(); i++) {
		l = i, r = i;
		while(r < S.length() && S[r] == S[l]) r++;
		r--;
		if(r == l + 1) {
			ans += S[l];
		}
		else {
			for(j = 0; j < r - l; j++) {
				ans += S[l];
			}
		}
		i = r;
	}
	cout << ans;
	
	return 0;
}