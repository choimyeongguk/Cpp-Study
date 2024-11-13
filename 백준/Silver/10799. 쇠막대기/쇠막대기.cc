#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int i, l, ans = 0;
	string input;
	vector<int> stack;
	
	cin >> input;
	for(auto& c : input) {
		if(c == '(') {
			stack.push_back(0);
		}
		if(c == ')') {
			if(!stack.back()) {  // '('인 경우  
				stack.back() = 1;
			}
			else {  // 숫자인 경우 
				ans += stack.back() + 1;
				stack.erase(stack.end() - 2);
			}
			if(stack.back() && stack[stack.size() - 2]) {
				stack[stack.size() - 2] += stack.back();
				stack.pop_back();
			}
		}
	}
	cout << ans;
	
	return 0;
}