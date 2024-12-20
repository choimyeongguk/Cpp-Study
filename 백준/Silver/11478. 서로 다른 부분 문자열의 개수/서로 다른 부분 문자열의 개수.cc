#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string S;
	unordered_set<string> subS;
	
	cin >> S;
	for(int i = 1; i <= S.size(); i++) {
		for(int j = 0; j <= S.size() - i; j++) {
			subS.insert(S.substr(j, i));
		}
	}
	cout << subS.size();
	
	return 0;
}