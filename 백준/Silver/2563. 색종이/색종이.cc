#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	bool paper[101][101] = { false };
	int n, x, y, cnt = 0, i, j;
	
	cin >> n;
	while(n--) {
		cin >> x >> y;
		for(i = 0; i < 10; i++) {
			for(j = 0; j < 10; j++) {
				paper[y + i][x + j] = true;
			}
		}
	}
	for(i = 0; i <= 100; i++) {
		for(j = 0; j <= 100; j++) {
			if(paper[i][j]) cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}