#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	char cmd, c;
	int M, i;
	string S;
	stack<char> R;
	
	cin >> S >> M;
	for(i = 0; i < M; i++) {
		cin >> cmd;
		switch(cmd) {
			case 'L' :
				if(!S.empty()) {
					R.push(S.back());
					S.pop_back();
				}
				break;
			case 'D' :
				if(!R.empty()) {
					S += R.top();
					R.pop();
				}
				break;
			case 'B' :
				if(!S.empty())
					S.pop_back();
				break;
			case 'P' :
				cin >> c;
				S += c;
				break;
		}
	}
	cout << S;
	while(!R.empty()) {
		cout << R.top();
		R.pop();
	}
	
	return 0;
}