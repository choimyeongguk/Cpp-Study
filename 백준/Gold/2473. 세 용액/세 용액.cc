#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long N, sum, ans, absMin, l, r, tL, tR, I, L, R, i;
	long long sol[5000];
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> sol[i];
	}
	sort(sol, sol + N);
	
	ans = 40000000000;
	for(i = 0; i < N - 2; i++) {
		l = i + 1;
		r = N - 1;
		absMin = 40000000000;
		while(l < r) {
			if(abs(absMin) > abs(sum = sol[i] + sol[l] + sol[r])) {
				absMin = sum;
				tL = l;
				tR = r;
			}
			if(sol[i] + sol[l] + sol[r] > 0) {
				r--;
			}
			else {
				l++;
			}
		}
		if(abs(ans) > abs(absMin)) {
			ans = absMin;
			I = i;
			L = tL;
			R = tR;
		}
	}
	cout << sol[I] << " " << sol[L] << " " << sol[R];
	
	return 0;
}