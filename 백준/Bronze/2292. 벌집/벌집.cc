#include <bits/stdc++.h>
using namespace std;

int getLayer(int x) {
	int num = 0, result = 1;
	x--;
	while(x > 0) {
		result++;
		num += 6;
		x -= num;
	}
	return result;
}

int main() {
	int N;
	
	cin >> N;
	cout << getLayer(N);
	
	return 0; 
}