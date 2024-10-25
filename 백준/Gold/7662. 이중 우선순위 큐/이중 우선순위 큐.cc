#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	char cmd;
	int T, k, v, idx, i, j;
	vector<bool> isRemain;
	priority_queue<pair<int,int>> maxQ;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minQ;
	
	cin >> T;
	for(i = 0; i < T; i++) {
		cin >> k;
		isRemain.clear();
		for(idx = 0, j = 0; j < k; j++) {
			cin >> cmd >> v;
			if(cmd == 'I') {
				maxQ.push({v, idx});
				minQ.push({v, idx});
				isRemain.push_back(true);
				idx++;
			} else {
				if(v == -1) {
					if(minQ.empty()) continue;
					while(!minQ.empty() && isRemain[minQ.top().second] == false) minQ.pop();
					if(minQ.empty()) continue;
					isRemain[minQ.top().second] = false;
					minQ.pop();
				} else {
					if(maxQ.empty()) continue;
					while(!maxQ.empty() && isRemain[maxQ.top().second] == false) maxQ.pop();
					if(maxQ.empty()) continue;
					isRemain[maxQ.top().second] = false;
					maxQ.pop();
				}
			}
		}
		while(!minQ.empty() && isRemain[minQ.top().second] == false) minQ.pop();
		while(!maxQ.empty() && isRemain[maxQ.top().second] == false) maxQ.pop();
		if(minQ.empty()) {
			cout << "EMPTY\n";
		} else {
			cout << maxQ.top().first << " " << minQ.top().first << "\n";
		}
		while(!minQ.empty()) minQ.pop();
		while(!maxQ.empty()) maxQ.pop();
	}
	
	return 0;
}