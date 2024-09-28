#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, i, j;
	string S;
	stack<char> stack;
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> S;
		for(j = 0; j < S.length(); j++) {
			if(!stack.empty() && stack.top() == '(' && S[j] == ')') {
				stack.pop();
				continue;
			}
			stack.push(S[j]);
		}
		cout << (stack.empty() ? "YES" : "NO") << '\n';
		while(!stack.empty()) stack.pop();
	}
	
	return 0;
}