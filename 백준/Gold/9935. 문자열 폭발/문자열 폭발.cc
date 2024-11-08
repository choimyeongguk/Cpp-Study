#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string S, bomb, stack;
	
	cin >> S >> bomb;
	for(auto& c : S) {
		stack += c;
		if(c == bomb[bomb.size() - 1] && stack.size() >= bomb.size() && stack.substr(stack.size() - bomb.size(), bomb.size()) == bomb) {
			stack.erase(stack.size() - bomb.size(), bomb.size());
		}
	}
	cout << (stack.size() ? stack : "FRULA");
	
	return 0;
}