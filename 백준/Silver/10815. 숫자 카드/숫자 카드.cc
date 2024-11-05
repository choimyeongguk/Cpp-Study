#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, num, i;
	
	cin >> N;
	vector<int> card(N);
	for(auto& e : card) {
		cin >> e;
	}
	sort(card.begin(), card.end());
	cin >> M;
	for(i = 0; i < M; i++) {
		cin >> num;
		cout << binary_search(card.begin(), card.end(), num) << " ";
	}
	
	
	return 0;
}