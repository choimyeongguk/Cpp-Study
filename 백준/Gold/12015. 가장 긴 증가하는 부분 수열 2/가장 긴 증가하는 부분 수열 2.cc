#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, num, i;
	vector<int> LIS;
	vector<int>::iterator it;
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> num;
		it = lower_bound(LIS.begin(), LIS.end(), num);
		if(it == LIS.end()) LIS.emplace_back(num);
		else *it = num;
	}
	
	cout << LIS.size();
	
	return 0;
}