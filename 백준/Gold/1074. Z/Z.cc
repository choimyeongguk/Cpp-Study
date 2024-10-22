#include <bits/stdc++.h>
using namespace std;

int N, r, c;

int Z(int L) {
	if(L == 1) return 0;
	int l = L >> 1, i = 0;
	if(r >= l && c >= l) i = 3, r -= l, c -= l;
	else if(r >= l) 	 i = 2, r -= l;
	else if(c >= l)		 i = 1, c -= l;
	return l * l * i + Z(l);
}

int main() {
	cin >> N >> r >> c;
	cout << Z(1 << N);
	return 0;
}