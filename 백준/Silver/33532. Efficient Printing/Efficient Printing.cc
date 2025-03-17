#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, five = 5, cnt, ans = 0;
	cin >> n;
	while(true) {
		cnt = n / five;
		if(cnt == 0) break;
		ans += cnt;
		five *= 5;
	}
	cout << ans;
	
	return 0;
}