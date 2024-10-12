#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	bool chk, result = true;
	int N, k, num, i;
	vector<queue<int>> Q;
	queue<int> exit;
	
	cin >> N >> k;
	Q.assign(k + 1, queue<int>());
	for(i = 1; i <= N; i++) {
		cin >> num;
		exit.push(num);
		Q[0].push(i);
	}
	
	while(!exit.empty()) {
		num = exit.front();
		chk = false;
		for(i = 0; i < k; i++) {
			if(Q[i].empty()) continue;
			while(Q[i].front() < num) {
				Q[i+1].push(Q[i].front());
				Q[i].pop();
			}
			if(Q[i].front() == num) {
				exit.pop();
				Q[i].pop();
				chk = true;
				break;
			}
		}
		if(!chk) {
			result = false;
			break;
		}
	}
	cout << (result ? "YES" : "NO");
	
	return 0;
}