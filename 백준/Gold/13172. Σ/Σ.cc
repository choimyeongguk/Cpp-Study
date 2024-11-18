#include <bits/stdc++.h>
#define X 1000000007
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll M, N, S, E, exp, ans = 0, i;
	
	cin >> M;
	for(i = 0; i < M; i++) {
		cin >> N >> S;
		
		E = 1, exp = X - 2;	// 기댓값, 지수 
		while(exp) {
			if(exp % 2)		// odd
				E = (E * N) % X;
			N = (N * N) % X;
			exp /= 2;
		}
		E = (E * S) % X;
		ans = (ans + E) % X;
	}
	cout << ans;
	
	return 0;
}