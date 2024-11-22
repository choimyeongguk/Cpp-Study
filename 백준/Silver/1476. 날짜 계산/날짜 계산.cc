#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int E, S, M, e, s, m, n;
	cin >> E >> S >> M;
	for(e = s = m = n = 1; E != e || S != s || M != m; n++) {
		if(++e == 16) e = 1;
		if(++s == 29) s = 1;
		if(++m == 20) m = 1;
	}
	cout << n;
	
	return 0;
}