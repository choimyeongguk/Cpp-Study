#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, num, nxt = 1, i;
	stack<int> stk;		// seq를 위해 임시 저장 
	queue<int> seq;		// 입력된 수열 저장
	queue<char> cmd;	// +/- 저장 
	
	cin >> n;
	for(i = 0; i < n; i++) {
		cin >> num;
		seq.push(num);
	}

	while(!seq.empty()) {
		if(stk.empty()) {
			stk.push(nxt++);
			cmd.push('+');
			continue;
		}
		if(seq.front() == stk.top()) {
			stk.pop();
			seq.pop();
			cmd.push('-');
		} else if(seq.front() > stk.top()) {
			stk.push(nxt++);
			cmd.push('+');
		} else {
			cout << "NO";
			return 0;
		}
	}
	while(!cmd.empty()) {
		cout << cmd.front() << '\n';
		cmd.pop();
	}
	
	return 0;
}