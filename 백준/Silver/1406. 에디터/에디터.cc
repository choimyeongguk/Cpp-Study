#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	char cmd, c;
	int M, i;
	string S;
	deque<char> L;
	stack<char> R;
	
	cin >> S >> M;
	for(auto& e : S)
		L.push_back(e);
	for(i = 0; i < M; i++) {
		cin >> cmd;
		switch(cmd) {
			case 'L' :
				if(!L.empty()) {
					R.push(L.back());
					L.pop_back();
				}
				break;
			case 'D' :
				if(!R.empty()) {
					L.push_back(R.top());
					R.pop();
				}
				break;
			case 'B' :
				if(!L.empty())
					L.pop_back();
				break;
			case 'P' :
				cin >> c;
				L.push_back(c);
				break;
		}
	}
	while(!L.empty()) {
		cout << L.front();
		L.pop_front();
	}
	while(!R.empty()) {
		cout << R.top();
		R.pop();
	}
	
	return 0;
}