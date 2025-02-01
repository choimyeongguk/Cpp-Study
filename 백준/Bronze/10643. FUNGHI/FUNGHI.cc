#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int ans, sum, num, i;
	queue<int> hansel, gretel;
	
	for(i = 0; i < 4; i++) {
		cin >> num;
		hansel.push(num);
	}
	for(sum = 0, i = 0; i < 4; i++) {
		cin >> num;
		sum += num;
		gretel.push(num);
	}
	for(ans = sum, i = 0; i < 7; i++) {
		sum -= gretel.front();
		sum += hansel.front();
		hansel.push(gretel.front());
		gretel.pop();
		gretel.push(hansel.front());
		hansel.pop();
		ans = ans > sum ? ans : sum;
	}
	cout << ans;
	
	return 0;
}