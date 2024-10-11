#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, start, end, i;
	vector<int> sum;
	
	cin >> N >> M;
	sum.assign(N+1, 0);
	cin >> sum[1];
	for(i = 2; i <= N; i++) {
		cin >> sum[i];
		sum[i] += sum[i-1];
	}
	for(i = 0; i < M; i++) {
		cin >> start >> end;
		cout << sum[end] - sum[start-1] << '\n';
	}
	
	return 0;
}