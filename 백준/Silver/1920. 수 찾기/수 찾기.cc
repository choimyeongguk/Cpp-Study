#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, tmp, i;
	vector<int> nums;
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> tmp;
		nums.push_back(tmp);
	}
	sort(nums.begin(), nums.end());
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> tmp;
		cout << binary_search(nums.begin(), nums.end(), tmp) << '\n';
	}
	
	return 0;
}