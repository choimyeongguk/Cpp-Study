#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long tmp, ans = 0;
	string input;
	stack<long long> st;
	
	cin >> input;
	for(auto& c : input) {
		switch(c) {
			case '(' :
				st.push(-1);
				break;
			case '[' :
				st.push(-2);
				break;
			case ')' :
				if(st.empty()) {
					cout << 0;
					return 0;
				}
				if(st.top() == -1) {
					st.pop();
					st.push(2);
				}
				else if(st.top() > 0) {
					tmp = 0;
					while(!st.empty() && st.top() > 0) {
						tmp += st.top();
						st.pop();
					}
					if(st.empty() || st.top() != -1) {
						cout << 0;
						return 0;
					}
					else {
						st.pop();
						st.push(tmp * 2);
					}
				}
				else {
					cout << 0;
					return 0;
				}
				break;
			case ']' :
				if(st.empty()) {
					cout << 0;
					return 0;
				}
				if(st.top() == -2) {
					st.pop();
					st.push(3);
				}
				else if(st.top() > 0) {
					tmp = 0;
					while(!st.empty() && st.top() > 0) {
						tmp += st.top();
						st.pop();
					}
					if(st.empty() || st.top() != -2) {
						cout << 0;
						return 0;
					}
					else {
						st.pop();
						st.push(tmp * 3);
					}
				}
				else {
					cout << 0;
					return 0;
				}
				break;
		}
	}
	while(!st.empty()) {
		if(st.top() < 0) {
			cout << 0;
			return 0;
		}
		ans += st.top();
		st.pop();
	}
	cout << ans;
	
	return 0;
}