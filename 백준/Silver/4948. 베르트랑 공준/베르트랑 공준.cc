#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	bool chk;
	int n, i, j;
	vector<int> p(1, 2);
	
	for(i = 3; i <= 246912; i++) {		
		for(chk = true, j = 0; p[j]*p[j] <= i; j++) {
			if(i % p[j] == 0) {
				chk = false;
				break;
			}
		}
		if(chk) p.push_back(i);
	}
	
	while(true) {
		cin >> n;
		if(!n) break;
		cout << upper_bound(p.begin(), p.end(), 2 * n) - upper_bound(p.begin(), p.end(), n) << "\n";
	}
	
	return 0;
}