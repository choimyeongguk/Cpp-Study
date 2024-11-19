#include <bits/stdc++.h>
using namespace std;

void hanoi(int N, int start, int via, int to){
	if(N == 1) {
		cout << start << " " << to << "\n";
	} else {
		hanoi(N - 1, start, to, via);
		cout << start << " " << to << "\n";
		hanoi(N - 1, via, start, to);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	
	cin >> N;
	cout << (1 << N) - 1 << "\n";
	hanoi(N, 1, 2, 3);
	
	return 0;
}