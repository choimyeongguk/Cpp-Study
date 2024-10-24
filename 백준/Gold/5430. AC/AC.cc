#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T, n, i, j;
	bool status, chk;
	string p, arr, num;
	deque<int> deque;
	
	cin >> T;
	for(i = 0; i < T; i++) {
		cin >> p >> n >> arr;
		
		for(auto& c : arr) {
			if(c == ',' || c == '[' || c == ']') {
				if(!num.length()) continue;
				deque.push_back(stoi(num));
				num = "";
			} else {
				num += c;
			}
		}
		
		status = true, chk = false;
		for(auto& c : p) {
			if(c == 'R') {
				status = !status;
			} else {
				if(deque.empty()) {
					chk = true;
					break;
				}
				if(status) deque.pop_front();
				else deque.pop_back();
			}
		}
		
		if(chk) {
			cout << "error\n";
			continue;
		}
		
		cout << "[";
		if(deque.empty()) {
			cout << "]\n";
			continue;
		}
		if(status) {
			for(j = 0; j < deque.size() - 1; j++) {
				cout << deque[j] << ",";
			}
			cout << deque.back() << "]\n";
		} else {
			for(j = deque.size() - 1; j > 0; j--) {
				cout << deque[j] << ",";
			}
			cout << deque.front() << "]\n";
		}
		
		deque.clear();
	}
	
	return 0;
}