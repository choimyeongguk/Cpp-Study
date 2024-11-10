#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string expr;
	stack<char> op;
	
	cin >> expr;
	
	// 우선순위 : ')' > '*' = '/' >  '+' = '-' > '('
	// 우선순위가 높은 연산자가 먼저 나와야 함
	// -> 자신보다 우선순위 높은 연산자가 이미 top에 있으면 빼내주기 
	for(auto& c : expr) {
		switch(c) {
			case '(' :
				op.push(c);
				break;
			
			case ')' :
				while(op.top() != '(') {
					cout << op.top();
					op.pop();
				}
				op.pop();
				break;
				
			case '*' : case '/' :
				while(!op.empty() && (op.top() == '*' || op.top() == '/')) {
					cout << op.top();
					op.pop();
				}
				op.push(c);
				break;
			
			case '+' : case '-' :
				while(!op.empty() && op.top() != '(') {
					cout << op.top();
					op.pop();
				}
				op.push(c);
				break;
			
			default :
				cout << c;
		}
	}
	while(!op.empty()) {
		cout << op.top();
		op.pop();
	}
	return 0;
}