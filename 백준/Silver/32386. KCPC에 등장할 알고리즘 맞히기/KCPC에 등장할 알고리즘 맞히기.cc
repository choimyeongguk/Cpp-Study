#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, max = 0, s, t, i, j;
	map<string,int> tag;
	string a, ans;
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> s >> t;
		for(j = 0; j < t; j++) {
			cin >> a;
			tag[a]++;
		}
	}
	for(auto& e : tag) {
		if(e.second > max) {
			max = e.second; 
			ans = e.first;
		}
		else if(e.second == max) {
			ans = "-1";
		}
	}
	cout << ans;
	
	return 0;
}