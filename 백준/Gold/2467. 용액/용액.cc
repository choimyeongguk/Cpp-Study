#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, i;
	int diff = 2000000000, first, second;
	vector<int> solution;
	
	cin >> N;
	solution.resize(N + 1);
	for(i = 1; i <= N; i++) {
		cin >> solution[i];
	}
	for(i = 1; i < N; i++) {
		auto it = lower_bound(solution.begin() + i + 1, solution.end(), -solution[i]);
		if(it != solution.end() && diff > abs(solution[i] + *it)) {
			diff = abs(solution[i] + *it);
			first = i;
			second = it - solution.begin();
		}
		it--;
		if(i != it - solution.begin() && diff > abs(solution[i] + *it)) {
			diff = abs(solution[i] + *it);
			first = i;
			second = it - solution.begin();
		}
		if(!diff)
			break;
	}
	cout << solution[first] << " " << solution[second];
	
	return 0;
}