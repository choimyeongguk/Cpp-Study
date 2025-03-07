#include <bits/stdc++.h>
using namespace std;

vector<int> card;
int pa[4000001];
bool used[4000001] = { false };

int root(int x) {
	if(!used[pa[x]]) return pa[x];
	return pa[x] = root(pa[x]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, K, idx, num, i;
	
	cin >> N >> M >> K;
	
	card.resize(M);
	for(auto& e : card)
		cin >> e;
	sort(card.begin(), card.end());
	
	idx = 1;
	for(auto& e : card) {
		while(idx < e) pa[idx++] = e;
	}
	
	for(i = 0; i < K; i++) {
		cin >> num;
		num = root(num);
		used[num] = true;
		cout << num << "\n";
	}
	
	return 0;
}