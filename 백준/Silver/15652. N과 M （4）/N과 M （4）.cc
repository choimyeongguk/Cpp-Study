#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> arr;

void solution(int x) {
	if(arr.size() == M) {
		for(auto& e : arr) {
			cout << e << " ";
		}
		cout << "\n";
		return;
	}
	for(int i = x; i <= N; i++) {
		arr.push_back(i);
		solution(i);
		arr.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	solution(1);
	
	return 0;
}