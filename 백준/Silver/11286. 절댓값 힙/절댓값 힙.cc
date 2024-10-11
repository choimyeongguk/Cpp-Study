#include <bits/stdc++.h>
using namespace std;

struct compare {
	bool operator()(const int& a, const int& b) {
		if(abs(a) == abs(b)) {
			return a > b;
		}
		return abs(a) > abs(b);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, cmd, i;
	priority_queue<int, vector<int>, compare> pq;
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> cmd;
		if(cmd) {
			pq.push(cmd);
		} else if(pq.empty()){
			cout << 0 << '\n';
		} else {
			cout << pq.top() << '\n';
			pq.pop();
		}
	}

	return 0;
}