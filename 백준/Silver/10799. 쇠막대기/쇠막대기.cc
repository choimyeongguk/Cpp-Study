#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int i, l, ans = 0;
	string input, stack;
	
	cin >> input;
	for(i = 0; i < input.size(); i++) {
		if(input[i] == '(') {
			stack += input[i];
		}
		if(input[i] == ')') {
			if(stack.back() == '(') {
				stack.back() = '|';
			}
			else if(stack.back() == '|') {
				for(l = stack.size() - 1; stack[l] == '|'; l--);
				ans += stack.size() - l;
				stack.erase(l, 1);
			}
			else {
				stack += input[i];
			}
		}
	}
	cout << ans;
	
	return 0;
}