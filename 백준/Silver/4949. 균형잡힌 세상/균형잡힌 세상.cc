#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	bool chk;
	string input;
	stack<char> stack;
	
	while(true) {
		chk = true;
		getline(cin, input);
		
		if(input == ".") {
			break;
		}
		
		for(int i = 0; i < input.length(); i++) {
			if(input[i] == '(' || input[i] == '[') {
				stack.push(input[i]);
			} else if(input[i] == ')' || input[i] == ']') {
				if(!stack.empty() && stack.top() == (input[i]==')'?'(':'[')) {
					stack.pop();
				} else {
					chk = false;
					break;
				}
			}
		}
		if(!stack.empty()) {
			chk = false;
			while(!stack.empty()) {
				stack.pop();
			}
		}
		cout << (chk==true ? "yes" : "no") << '\n';
	}
	
	return 0;
}