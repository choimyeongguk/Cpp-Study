#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> arr;

void solution(int x, int depth) {
	if(depth == M) {
		for(int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for(int i = x; i <= N; i++) {
		arr[depth] = i;
		solution(i, depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	arr.resize(M);
	solution(1, 0);
	
	return 0;
}