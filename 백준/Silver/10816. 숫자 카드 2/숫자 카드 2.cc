#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, num, tmp, i;
	vector<int> card;
	
	cin >> N;
	card.assign(N, 0);
	for(i = 0; i < N; i++) {
		cin >> num;
		card[i] = num;
	}
	sort(card.begin(), card.end());
	
	cin >> M;
	for(i = 0; i < M; i++) {
		cin >> num;
		tmp = upper_bound(card.begin(), card.end(), num) - lower_bound(card.begin(), card.end(), num);
		cout << tmp << ' ';
	}
	
	return 0;
}