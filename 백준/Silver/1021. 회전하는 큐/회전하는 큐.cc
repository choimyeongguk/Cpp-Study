#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, target, cnt, ans = 0, i;
	queue<int> q;
	
	cin >> N >> M;
	for(i = 1; i <= N; i++)
		q.push(i);
	for(i = 0; i < M; i++) {
		cin >> target;
		cnt = 0;
		while(q.front() != target) {
			q.push(q.front());
			q.pop();
			cnt++;
		}
		ans += min(cnt, (int)q.size() - cnt);
		q.pop();
	}
	cout << ans;
	
	return 0;
}