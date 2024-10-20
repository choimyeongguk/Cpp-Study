#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T, N, ans, i, j;
	string name, type;
	unordered_map<string,int> clothes;
	
	cin >> T;
	for(i = 0; i < T; i++) {
		cin >> N;
		for(j = 0; j < N; j++) {
			cin >> name >> type;
			if(clothes.find(type) != clothes.end()) {
				(clothes.find(type)->second)++;
			} else {
				clothes.insert({type,1});
			}
		}
		ans = 1;
		for(auto& e : clothes) {
			ans *= e.second + 1;
		}
		cout << ans - 1 << "\n";
		clothes.clear();
	}
	
	return 0;
}