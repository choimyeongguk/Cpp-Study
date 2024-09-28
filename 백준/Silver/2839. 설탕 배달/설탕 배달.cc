#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, five, three = 0;
	
	cin >> N;
	if(N == 1 || N == 2 || N == 4 || N == 7) {
		cout << -1;
		return 0;
	}
	five = N / 5;
	switch(N % 5) {
		case 0:
			break;
		case 1:
			five -= 1;
			three += 2;
			break;
		case 2:
			five -= 2;
			three += 4;
			break;
		case 3:
			three += 1;
			break;
		case 4:
			five -= 1;
			three += 3;
			break;
	}
	cout << five + three;
	
	return 0;
}