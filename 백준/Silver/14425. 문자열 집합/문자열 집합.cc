#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, ans = 0, i;
	string tmp;
	vector<string> S;
	
	cin >> N >> M;
	
	S.resize(N);
	for(i = 0; i < N; i++)
		cin >> S[i];
	sort(S.begin(), S.end());
	
	for(i = 0; i < M; i++) {
		cin >> tmp;
		if(binary_search(S.begin(), S.end(), tmp))
			ans++;
	}
	cout << ans;
	
	return 0;
}