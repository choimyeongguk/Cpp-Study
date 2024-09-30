#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, num, nxt = 1, i;
	stack<int> stk;		// seq를 위해 임시 저장 
	vector<char> cmd;	// +/- 저장 
	
	cin >> n;
	while(n--) {
		cin >> num;
		while(nxt <= num) {
			stk.push(nxt++);
			cmd.push_back('+');
		}
		if(stk.top() == num) {
			stk.pop();
			cmd.push_back('-');
		} else {
			cout << "NO";
			return 0;
		}
	}
	for(char& e : cmd) {
		cout << e << '\n';
	}
	
	return 0;
}