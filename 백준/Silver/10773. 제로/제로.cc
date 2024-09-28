#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, sum = 0, num, i;
	int stack[100000]; int top = 0;
	
	cin >> N;
	//stack.assign(N, 0);
	for(i = 0; i < N; i++) {
		cin >> num;
		if(num) stack[top++] = num;
		else top--;
	}
	for(i = 0; i < top; i++) {
		sum += stack[i];
	}
//	while(!stack.empty()) {
//		sum += stack.top();
//		stack.pop();
//	}
	cout << sum;
	
	return 0;
}