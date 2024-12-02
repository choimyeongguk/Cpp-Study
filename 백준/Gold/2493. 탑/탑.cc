#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, h, i;
	stack<pair<int,int>> stack;
	
	cin >> N;
	for(i = 1; i <= N; i++) {
		cin >> h;
		while(!stack.empty() && stack.top().first < h) {
			stack.pop();
		}
		if(stack.empty()) {
			cout << "0 ";
		}
		else {
			cout << stack.top().second << " ";
		}
		stack.push({h, i});
	}
	
	return 0;
}