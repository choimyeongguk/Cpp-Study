#include <bits/stdc++.h>
using namespace std;

int N, r, c;

int dfs(int size) {
	if(size == 1) return 0;
	int n = size >> 1, i = 0;
	if(r >= n && c >= n) i = 3, r -= n, c -= n;
	else if(r >= n) 	 i = 2, r -= n;
	else if(c >= n)		 i = 1, c -= n;
	return n * n * i + dfs(n);
}

int main() {
	cin >> N >> r >> c;
	cout << dfs(1 << N);
	
	return 0;
}