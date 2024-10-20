#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, i;
	string tmp;
	vector<string> pokemon1;
	map<string,int> pokemon2;
	
	cin >> N >> M;
	pokemon1.assign(N + 1, "");
	for(i = 1; i <= N; i++) {
		cin >> pokemon1[i];
		pokemon2.insert({pokemon1[i], i});
	}
	for(i = 0; i < M; i++) {
		cin >> tmp;
		if(isdigit(tmp[0])) {
			cout << pokemon1[stoi(tmp)] << "\n";
		} else {
			cout << pokemon2.find(tmp)->second << "\n";
		}
	}
	
	return 0;
}