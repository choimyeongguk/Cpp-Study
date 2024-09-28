#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, sum = 0, num, i;
	stack<int> stack;
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> num;
		if(num) stack.push(num);
		else stack.pop();
	}
	while(!stack.empty()) {
		sum += stack.top();
		stack.pop();
	}
	cout << sum;
	
	return 0;
}