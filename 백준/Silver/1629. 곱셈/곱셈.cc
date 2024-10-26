#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;

lld dnq(lld A, lld B, lld C) {
	if(B == 1) return A % C;
	
	lld tmp = dnq(A, B/2, C);
	if(B % 2) {  // 홀수 
		return ((tmp * tmp ) % C * A) % C;
	}
	return (tmp * tmp) % C;
}

int main() {
	lld A, B, C;
	cin >> A >> B >> C;
	cout << dnq(A, B, C);
	return 0;
}