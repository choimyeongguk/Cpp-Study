#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, ans, l, r, fl, fr, i;
	vector<char> fruit;
	
	cin >> N;
	fruit.resize(N);
	for(auto& e : fruit) cin >> e;
	
	ans = l = -1;
	fl = fr = fruit[0];
	for(i = 0; i < N; i++) {
		r = i;
		if(fruit[i] != fl && fruit[i] != fr) {
			fr = fruit[i];
			fl = fruit[i - 1];
			for(l = i; fruit[l] == fl || fruit[l] == fr; l--);
		}
		if(ans < r - l) ans = r - l;
	}
	cout << ans;
	
	return 0;
}