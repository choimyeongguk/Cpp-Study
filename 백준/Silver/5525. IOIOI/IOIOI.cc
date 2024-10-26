#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	char tmp;
	int N, M, ans = 0, prev1, prev2, prev3, i;
	int I = -6, O = 0;
	stack<int> S;
	
	cin >> N >> M;
	cin >> tmp; S.push(tmp - 'O');
	cin >> tmp; S.push(tmp - 'O');
	for(i = 2; i < M; i++) {
		cin >> tmp;
		if(tmp == 'I') {
			prev1 = S.top(); S.pop();
			prev2 = S.top(); S.pop();
			if(prev1 == 0 && prev2 == -6) {
				if(!S.empty() && S.top() > 0) {
					prev3 = S.top(); S.pop();
					S.push(prev3 + 1);
					S.push(I);
				} else {
					S.push(1);
					S.push(I);
				}
			} else {
				S.push(prev2);
				S.push(prev1);
				S.push(I);
			}
		} else S.push(O);
	}
	while(!S.empty()) {
		if(S.top() >= N) ans += S.top() - N + 1;
		S.pop();
	}
	cout << ans;
	
	return 0;
}