#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, num, i;
	vector<int> arr;
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	for(int e : arr) {
		cout << e << '\n';
	}
	
	return 0;
}