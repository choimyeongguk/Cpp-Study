#include <bits/stdc++.h>
using namespace std;

int getGcd(int x, int y) {
	if(y == 0) {
		return x;
	}
	return getGcd(y, x%y);
}

int main() {
	int a, b, gcd, lcm;
	
	cin >> a >> b;
	//gcd = getGcd(a, b);
	gcd = __gcd(a, b);
	lcm = a * b / gcd;
	cout << gcd << '\n' << lcm;
	
	return 0;
}