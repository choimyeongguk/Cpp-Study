#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, num, i;
	string cmd;
	stack<int> stack;
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> cmd;
		switch(cmd[0]) {
			case 'p' :
				if(cmd[1] == 'u') {
					cin >> num;
					stack.push(num);
				} else {
					if(stack.empty()) {
						cout << -1 << '\n';
					} else {
						cout << stack.top() << '\n';
						stack.pop();
					}
				}
				break;
				
			case 's' :
				cout << stack.size() << '\n';
				break;
				
			case 'e' :
				cout << stack.empty() << '\n';
				break;
				
			case 't' :
				cout << (stack.empty() ? -1 : stack.top()) << '\n';
				break;
		}
	}
	
	return 0;
}