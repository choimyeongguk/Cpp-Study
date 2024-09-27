#include <bits/stdc++.h>
using namespace std;

bool isEndNum(int x) {
	int cnt = 0;
	while(x) {
		if(x%10 == 6) {
			cnt++;
			if(cnt == 3) {
				return true;
			}
		} else {
			cnt = 0;
		}
		x /= 10;
	}
	return false;
}

int main() {
	int N, cnt = 0, i;
	
	cin >> N;
	for(i = 666; cnt < N; i++) {
		if(isEndNum(i)) {
			cnt++;
		}
	}
	cout << i - 1;
	
	return 0;
}