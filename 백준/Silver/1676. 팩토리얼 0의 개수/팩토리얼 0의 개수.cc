#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, cnt = 0, tmp;
	
	cin >> N;
	for(int i = N; i > 0; i--) {
		tmp = i;
		while(!(tmp % 5)) {
		cnt++;
		tmp /= 5;
		}
	}
	cout << cnt;
	
	return 0;
}