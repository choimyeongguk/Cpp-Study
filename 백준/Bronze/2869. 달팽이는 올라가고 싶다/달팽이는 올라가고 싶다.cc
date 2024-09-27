#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B, V, D;
	
	cin >> A >> B >> V;
	D = (V - A) / (A - B);
	if((V - A) % (A - B) > 0) {
		D += 2;
	} else {
		D += 1;
	}
	cout << D;
	
	return 0;
}