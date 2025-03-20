#include <bits/stdc++.h>
using namespace std;

void solve() {
	string input;
	stack<char> pwdL, pwdR;
	
	cin >> input;
	for(auto& c : input) {
		switch(c) {
			case '-' :
				if(!pwdL.empty()) {
					pwdL.pop();
				}
				break;
			case '<' :
				if(!pwdL.empty()) {
					pwdR.push(pwdL.top());
					pwdL.pop();
				}
				break;
			case '>' :
				if(!pwdR.empty()) {
					pwdL.push(pwdR.top());
					pwdR.pop();
				}
				break;
			default :
				pwdL.push(c);
		}
	}
	while(!pwdL.empty()) {
		pwdR.push(pwdL.top());
		pwdL.pop();
	}
	while(!pwdR.empty()) {
		cout << pwdR.top();
		pwdR.pop();
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
	
	return 0;
}