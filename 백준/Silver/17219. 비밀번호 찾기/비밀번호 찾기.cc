#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, i;
	string name, pw;
	unordered_map<string,string> memo;
	
	cin >> N >> M;
	for(i = 0; i < N; i++) {
		cin >> name >> pw;
		memo.insert({name, pw});
	}
	for(i = 0; i < M; i++) {
		cin >> name;
		cout << memo.find(name)->second << "\n";
	}
	
	return 0;
}