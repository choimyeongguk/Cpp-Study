#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, num, tmp, ans = 0, i;
	priority_queue<int, vector<int>, greater<int>> pq;
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> num;
		pq.push(num);
	}
	while(pq.size() > 1) {
		tmp = pq.top(), pq.pop();
		tmp += pq.top(), pq.pop();
		ans += tmp;
		pq.push(tmp);
	}
	cout << ans;
	
	return 0;
}