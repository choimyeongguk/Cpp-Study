#include <bits/stdc++.h>
using namespace std;

int N, ans = 0;
bool vertical[15] = { 0 };
bool diagonal1[30] = { 0 };  // r + c. 우상향 
bool diagonal2[30] = { 0 };  // r - c. 우하향 
// r + c 또는 r - c 가 같은 위치 끼리는 같은 대각선상에 있음

void nQueen(int depth) {
	if(depth == N) {
		ans++;
		return;
	}
	for(int i = 0; i < N; i++) {
		if(vertical[i] || diagonal1[depth + i] || diagonal2[depth - i + N - 1]) continue;
		vertical[i] = true;
		diagonal1[depth + i] = true;
		diagonal2[depth - i + N - 1] = true;
		nQueen(depth + 1);
		vertical[i] = false;
		diagonal1[depth + i] = false;
		diagonal2[depth - i + N - 1] = false;
	}
}

int main() {
	cin >> N;
	nQueen(0);
	cout << ans;
	return 0;
}