#include <bits/stdc++.h>
using namespace std;

int main() {
	char prev = '\n', c;
	stack<char> stack;
	
	while(true) {
		c = getchar();
		
		switch(c) {
			case '.' :
				if(prev == '\n') {
					return 0;
				}
				if(stack.size()) {
					cout << "no" << '\n';
					while(!stack.empty()) stack.pop();
				} else {
					cout << "yes" << '\n';
				}
				break;
				
			case '(' : case '[' :
				stack.push(c);
				break;
				
			case ')' : case ']' :
				if(!stack.empty() && stack.top() == (c==')'?'(':'[')) {
					stack.pop();
				} else {
					stack.push(c);
				}
				break;
		}
		prev = c;
	}
	
	return 0;
}