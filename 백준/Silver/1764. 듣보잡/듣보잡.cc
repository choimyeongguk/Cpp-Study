#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, cnt = 0, i;
	vector<string> S;
	vector<string> dbj;
	
	cin >> N >> M;
	N += M;
	S.assign(N, string());
	for(i = 0; i < N; i++) {
		cin >> S[i];
	}
	sort(S.begin(), S.end());
	
	for(i = 1; i < N; i++) {
		if(S[i-1] == S[i]) {
			cnt++;
			dbj.push_back(S[i]);
		}
	}
	
	cout << cnt << '\n';
	for(string& e : dbj) {
		cout << e << '\n';
	}
	
	return 0;
}