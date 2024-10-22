#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> arr;

void solution(int depth) {
	if(depth == M + 1) {
		for(int i = 1; i <= M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for(int i = arr[depth - 1]; i <= N; i++) {
		arr[depth] = i;
		solution(depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	arr.resize(M + 1);
	arr[0] = 1;
	solution(1);
	
	return 0;
}