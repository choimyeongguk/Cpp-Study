#include <bits/stdc++.h>
using namespace std;

int k;
vector<int> S;
vector<int> ans;

void comb(int start, int depth) {
	if(depth == 6) {
		for(auto& e : ans)
			cout << e << " ";
		cout << "\n";
		return;
	}
	for(int i = start; i < S.size(); i++) {
		ans.push_back(S[i]);
		comb(i + 1, depth + 1);
		ans.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	while(true) {
		cin >> k;
		if(!k) break;
		S.resize(k);
		for(int i = 0; i < k; i++)
			cin >> S[i];
			
		sort(S.begin(), S.end());
		comb(0, 0);
		cout << "\n";
	}
	
	return 0;
}