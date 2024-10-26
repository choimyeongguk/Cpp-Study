#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, ans, p1, p2, f1, f2, i;
	vector<int> fruit;
	
	cin >> N;
	
	fruit.resize(N);
	for(auto& e : fruit) {
		cin >> e;
	}
	
	p1 = p2 = 0;
	f1 = f2 = fruit[0];
	ans = 1;
	for(i = 1; i < N; i++) {
		p2 = i;
		if(fruit[i] != f1 && fruit[i] != f2) {
			f2 = fruit[i];
			f1 = fruit[i - 1];
			for(p1 = i - 1; fruit[p1] == f1 || fruit[p1] == f2; p1--);
			p1++;
		}
		if(ans < p2 - p1 + 1) ans = p2 - p1 + 1;
	}
	cout << ans;
	
	return 0;
}