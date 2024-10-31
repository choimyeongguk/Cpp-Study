#include <bits/stdc++.h>
using namespace std;

int d(int n) {
	int ret = n;
	while(n) {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	
	vector<bool> isSelf(10036, true);
	
	for(int i = 1; i <= 10000; i++) {
		isSelf[d(i)] = false;
	}
	for(int i = 1; i <= 10000; i++) {
		if(isSelf[i]) cout << i << "\n";
	}
	
	return 0;
}