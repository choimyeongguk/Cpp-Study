#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, num, i;
	string cmd;
	queue<int> queue;
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> cmd;
		switch(cmd[0]) {
			case 'p' :
				if(cmd[1] == 'u') {
					cin >> num;
					queue.push(num);
				} else {
					if(queue.empty()) {
						cout << -1 << '\n';
					} else {
						cout << queue.front() << '\n';
						queue.pop();
					}
				}
				break;
				
			case 's' :
				cout << queue.size() << '\n';
				break;
				
			case 'e' :
				cout << queue.empty() << '\n';
				break;
				
			case 'f' :
				cout << (queue.empty() ? -1 : queue.front()) << '\n';
				break;
			
			case 'b' :
				cout << (queue.empty() ? -1 : queue.back()) << '\n';
				break;
		}
	}
	
	return 0;
}