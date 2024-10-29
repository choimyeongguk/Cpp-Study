#include <bits/stdc++.h>
using namespace std;

bool isGroup(string S) {
	bool used[123] = { 0 };
	used[S[0]] = true;
	for(int i = 1; i < S.length(); i++) {
		if(S[i - 1] == S[i]) continue;
		if(used[S[i]]) return false;
		used[S[i]] = true;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, ans = 0, i;
	string word;
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> word;
		if(isGroup(word)) ans++;
	}
	cout << ans;
	
	return 0;
}