#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string S, bomb;
	string stack;
	
	cin >> S >> bomb;
	
	for(auto& c : S) {
		stack += c;
		if(c == bomb[bomb.size() - 1]) {
			if(stack.size() < bomb.size()) continue;
			if(stack.substr(stack.size() - bomb.size(), bomb.size()) == bomb) {
				stack.erase(stack.size() - bomb.size(), bomb.size());
			}
		}
	}
	cout << (stack.size() ? stack : "FRULA");
	
	return 0;
}