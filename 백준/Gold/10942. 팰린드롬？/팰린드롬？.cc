#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, l, r, i;
	int seq[2001];
	bool isPalindrome[2001][2001];
	
	cin >> N;
	for(i = 1; i <= N; i++) {
		cin >> seq[i];
	}
	
	for(i = 1; i <= N; i++) {
		l = r = i;
		while(1 <= l && r <= N && seq[l] == seq[r]) {
			isPalindrome[l--][r++] = true;
		}
		
		l = i, r = i + 1;
		while(1 <= l && r <= N && seq[l] == seq[r]) {
			isPalindrome[l--][r++] = true;
		}
	}
	
	cin >> M;
	for(i = 0; i < M; i++) {
		cin >> l >> r;
		cout << isPalindrome[l][r] << "\n";
	}
	
	return 0;
}