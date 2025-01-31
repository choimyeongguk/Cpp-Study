#include <bits/stdc++.h>
using namespace std;

int N, L;
char bar[100];

int canPass() {
	bool used[100] = { false };
	int loc = 0, h, i;
	while(loc < N - 1) {
		if(bar[loc] == bar[loc + 1]) {			// 평평한 길 
			loc++;
		}
		else if(bar[loc] == bar[loc + 1] + 1) {	// 내리막길 
			h = bar[loc + 1];
			for(i = 0; i < L; i++) {
				loc++;
				used[loc] = true;
				if(bar[loc] != h)
					return 0;
			}
		}
		else if(bar[loc] == bar[loc + 1] - 1) {	// 오르막길
			h = bar[loc];
			for(i = 0; i < L; i++) {
				if(bar[loc - i] != h || used[loc - i])
					return 0;
				used[loc - i] = true;
			}
			loc++;
		}
		else
			return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int ans, tmp, i, j;
	char M[100][100];
	
	cin >> N >> L;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			cin >> tmp;
			M[i][j] = tmp;
		}
	}
	
	ans = 0;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			bar[j] = M[i][j];
		}
		ans += canPass();
	}
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			bar[j] = M[j][i];
		}
		ans += canPass();
	}
	
	cout << ans;
	
	return 0;
}