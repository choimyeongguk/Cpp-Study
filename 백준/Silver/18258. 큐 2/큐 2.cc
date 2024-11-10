#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, x;
	string cmd;
	queue<int> q;
	
	cin >> N;
	while(N--) {
		cin >> cmd;
		if(cmd == "push") {
			cin >> x;
			q.push(x);
		} else if(cmd == "pop") {
			if(q.empty()) cout << "-1\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		} else if(cmd == "size") {
			cout << q.size() << "\n";
		} else if(cmd == "empty") {
			cout << q.empty() << "\n";
		} else if(cmd == "front") {
			if(q.empty()) cout << "-1\n";
			else cout << q.front() << "\n";
		} else {
			if(q.empty()) cout << "-1\n";
			else cout << q.back() << "\n";
		}
	}
	
	return 0;
}