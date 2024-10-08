#include <bits/stdc++.h>
using namespace std;

bool canProduce(long long int n, int x) {  // 입력 숫자, 푼 개수 
	n -= x;
	long long int tmp = x + 1;
	for(int i = 0; i < x; i++) {
		n -= tmp;
		tmp *= 2;
	}
	if(n > tmp) return false;
	return true;
}

int main() {
	long long int n;
	int x = 1;
	
	cin >> n;
	while(!canProduce(n, x++));
	cout << x - 1;
	
	return 0;
}