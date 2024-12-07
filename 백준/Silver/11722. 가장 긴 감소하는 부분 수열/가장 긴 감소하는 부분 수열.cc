#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, num, i;
	vector<int> lds;
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> num;
		auto it = lower_bound(lds.begin(), lds.end(), num, greater<int>());
		if(it == lds.end()) {
			lds.push_back(num);
		}
		else {
			*it = num;
		}
	}
	cout << lds.size();
	
	return 0;
}