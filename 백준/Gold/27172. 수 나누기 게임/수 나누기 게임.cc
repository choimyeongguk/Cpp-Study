#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, tmp, i, j;
	vector<int> point;
	vector<pair<int,int>> card;
	
	cin >> N;
	point.assign(N, 0);
	card.resize(N);
	for(i = 0; i < N; i++) {
		cin >> tmp;
		card[i] = { tmp, i };
	}
	sort(card.begin(), card.end());
	
	for(i = 0; i < N; i++) {
		for(j = card[i].first * 2; j <= card[N - 1].first; j += card[i].first) {
			auto it = lower_bound(card.begin() + i + 1, card.end(), make_pair(j, 0), 
                [](const pair<int, int>& a, const pair<int, int>& b) {
					return a.first < b.first;
					});
			if(it != card.end() && it->first == j) {
				point[card[i].second]++;
				point[it->second]--;
			}
		}
	}
	for(auto& e : point) {
		cout << e << " ";
	}
	
	return 0;
}