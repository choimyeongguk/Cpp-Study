#include <bits/stdc++.h>
using namespace std;

int type1 = 0, type2 = 0, type3 = 0;
int paper[2187][2187];

void divide(int r, int c, int s) {
	int type = paper[r][c];
	bool chk = true;
	for(int i = 0; i < s; i++) {
		for(int j = 0; j < s; j++) {
			if(paper[r + i][c + j] != type) {
				chk = false;
				break;
			}
		}
		if(!chk)
			break;
	}
	if(chk) {
		if(type == -1) type1++;
		else if(type == 0) type2++;
		else type3++;
		return;
	}
	s /= 3;
	divide(r, c, s);
	divide(r, c + s, s);
	divide(r, c + s + s, s);
	divide(r + s, c, s);
	divide(r + s, c + s, s);
	divide(r + s, c + s + s, s);
	divide(r + s + s, c, s);
	divide(r + s + s, c + s, s);
	divide(r + s + s, c + s + s, s);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, i, j;
	
	cin >> N;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}
	divide(0, 0, N);
	cout << type1 << "\n";
	cout << type2 << "\n";
	cout << type3;
	
	return 0;
}