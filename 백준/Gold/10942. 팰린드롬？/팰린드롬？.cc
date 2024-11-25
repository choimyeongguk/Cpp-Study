#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, l, r, i;
	int seq[2001];
	bool isPalindrome[2001][2001];
	// isPalindrome[i][j] = true/false : i에서 j까지 부분수열 팰린드롬 여부 
	
	cin >> N;
	for(i = 1; i <= N; i++) {
		cin >> seq[i];
	}
	
	for(i = 1; i <= N; i++) {	// 길이 홀수 팰린드롬 
		l = r = i;
		while(1 <= l && r <= N && seq[l] == seq[r]) {
			isPalindrome[l][r] = true;
			l--;
			r++; 
		}
		
		l = i, r = i + 1;
		while(1 <= l && r <= N && seq[l] == seq[r]) {
			isPalindrome[l][r] = true;
			l--;
			r++;
		}
	}
	
	cin >> M;
	for(i = 0; i < M; i++) {
		cin >> l >> r;
		cout << isPalindrome[l][r] << "\n";
	}
	
	return 0;
}