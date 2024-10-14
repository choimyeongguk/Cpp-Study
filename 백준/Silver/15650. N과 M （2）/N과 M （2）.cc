#include <bits/stdc++.h>
using namespace std;

int n, m;

void combination(int idx, int r, vector<int> combi) {
	if(combi.size() == r) {		// r개 만큼 선택 
		for(int i : combi) {	// 출력 
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}
	for(int i = idx + 1; i <= n; i++) {		// 마지막으로 선택한 idx 다음부터 하나씩 선택 
		combi.push_back(i);
		combination(i, r, combi);
		combi.pop_back();
	}
}

int main() {
	vector<int> c;
	cin >> n >> m;
	combination(0, m, c);
	return 0;
}