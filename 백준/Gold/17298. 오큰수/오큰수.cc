#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, A, i;
	stack<pair<int,int>> S;
	vector<int> NGE;
	
	cin >> N;
	NGE.assign(N, -1);
	for(i = 0; i < N; i++) {
		cin >> A;
		while(!S.empty() && S.top().first < A) {
			NGE[S.top().second] = A;
			S.pop();
		}
		S.push({A, i});
	}
	for(auto& e : NGE) {
		cout << e << " ";
	}
	
	return 0;
}