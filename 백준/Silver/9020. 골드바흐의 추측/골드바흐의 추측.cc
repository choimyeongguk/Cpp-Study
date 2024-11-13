#include <bits/stdc++.h>
using namespace std;

vector<int> prime;

void solve() {
	vector<int>::iterator l, r;
	int n;
	
	cin >> n;
	l = r = lower_bound(prime.begin(), prime.end(), n / 2);
	while(*l + *r != n) {
		if(*l + *r > n) l--;
		else if(*l + *r < n) r++;
	}
	cout << *l << " " << *r << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T, i, j;
	bool natural[10001] = { false };
	
	for(i = 2; i <= 10000; i++) {
		if(natural[i]) continue;
		for(j = 2; i * j <= 10000; j++) {
			natural[i * j] = true;
		}
	}
	for(i = 2; i <= 10000; i++) {
		if(!natural[i])
			prime.push_back(i);
	}
	
	cin >> T;
	while(T--) {
		solve();
	}
	
	return 0;
}