#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, num, i;
	string name;
	vector<pair<int, string>> memberList;
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> num >> name;
		memberList.push_back({num, name});
	}
	stable_sort(memberList.begin(), memberList.end(), [](auto& a, auto& b) {
		return a.first < b.first;
	});
	for(auto e : memberList) {
		cout << e.first << ' ' << e.second << '\n';
	}
	
	return 0;
}