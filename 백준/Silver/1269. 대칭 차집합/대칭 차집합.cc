#include <bits/stdc++.h>
using namespace std;

bool used[100000001] = { false };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int A, B, ans = 0, i;
	
	cin >> A >> B;
	A += B;
	for(i = 0; i < A; i++) {
		cin >> B;
		used[B] = !used[B];
	}
	for(i = 1; i <= 100000000; i++) {
		if(used[i])
			ans++;
	}
	cout << ans;
	
	return 0;
}