#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, num, sum, i;
	vector<int> line;
	
	cin >> N;
	line.assign(N, 0);
	for(i = 0; i < N; i++) {
		cin >> num;
		line[i] = num;
	}
	sort(line.begin(), line.end());
	sum = line[0];
	for(i = 1; i < N; i++) {
		line[i] += line[i-1];
		sum += line[i];
	}
	
	cout << sum;
	
	return 0;
}