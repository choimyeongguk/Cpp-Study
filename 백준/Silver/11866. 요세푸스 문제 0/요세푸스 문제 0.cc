#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, K, i;
	queue<int> table;
	
	cin >> N >> K;
	for(i = 1; i <= N; i++) {
		table.push(i);
	}
	
	cout << '<';
	while(table.size() > 1) {
		for(i = 1; i < K; i++) {
			table.push(table.front());
			table.pop();
		}
		cout << table.front() << ", ";
		table.pop();
	}
	cout << table.front() << '>';
	
	return 0;
}