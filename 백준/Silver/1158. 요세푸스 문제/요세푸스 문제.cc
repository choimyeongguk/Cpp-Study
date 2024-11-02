#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, K, idx = 0, i;
	vector<int> circle;
	
	cin >> N >> K;
	for(i = 1; i <= N; i++) {
		circle.push_back(i);
	}
	
	cout << "<";
	while(circle.size() > 1) {
		idx = (idx + K - 1) % circle.size();
		cout << circle[idx] << ", ";
		circle.erase(circle.begin() + idx);
	}
	cout << circle[0] << ">";
	
	return 0;
}