#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, ans = 0, i;
	string tmp;
	unordered_set<string> S;
	
	cin >> N >> M;
	
	for(i = 0; i < N; i++) {
		cin >> tmp;
		S.insert(tmp);
	}
	
	for(i = 0; i < M; i++) {
		cin >> tmp;
		if(S.find(tmp) != S.end())
			ans++;
	}
	cout << ans;
	
	return 0;
}