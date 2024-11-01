#include <bits/stdc++.h>
using namespace std;

int main() {
	int X, layer, r, c;
	cin >> X;
	for(layer = 1; X > layer; layer++) X -= layer;
	if(layer % 2) {
		r = layer - X + 1;
		c = X;
	} else {
		r = X;
		c = layer - X + 1;
	}
	cout << r << "/" << c;
	return 0;
}