#include <bits/stdc++.h>
using namespace std;

class Dq {
public:
	int val[100000];
	int s = 0;
	int e = 0;
	
	void idx_p(int& x) {
		x = (x + 100001) % 100000;
	}
	void idx_m(int& x) {
		x = (x + 99999) % 100000;
	}
	void push_front(int x) {
		idx_m(s);
		val[s] = x;
	}
	void push_back(int x) {
		val[e] = x;
		idx_p(e);
	}
	void pop_front() {
		if(s == e) cout << -1 << "\n";
		else {
			cout << val[s] << "\n";
			idx_p(s);
		}
	}
	void pop_back() {
		if(s == e) cout << -1 << "\n";
		else {
			idx_m(e);
			cout << val[e] << "\n";
		}
	}
	void size() {
		if(s <= e) cout << e - s << "\n";
		else cout << 100000 - (s - e) << "\n";
	}
	void empty() {
		cout << (s == e ? 1 : 0) << "\n";
	}
	void front() {
		cout << (s == e ? -1 : val[s]) << "\n";
	}
	void back() {
		if(s == e) cout << -1 << "\n";
		else {
			idx_m(e);
			cout << val[e] << "\n";
			idx_p(e);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, val;
	string cmd;
	Dq dq;
	
	cin >> N;
	while(N--) {
		cin >> cmd;
		if(cmd[0] == 'p') {
			if(cmd[1] == 'u') {
				cin >> val;
				if(cmd[5] == 'f') dq.push_front(val);
				else 			  dq.push_back(val);
			} else {
				if(cmd[4] == 'f') dq.pop_front();
				else			  dq.pop_back();
			}
		}
		else if(cmd[0] == 's') dq.size();
		else if(cmd[0] == 'e') dq.empty();
		else if(cmd[0] == 'f') dq.front();
		else 				   dq.back();
	}
	
	return 0;
}