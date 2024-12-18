#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string S;
	int cnt = 0, status;
	
	cin >> S;
	status = S[0];
	for(auto& e : S) {
		if(e != status) {
			status = e;
			cnt++;
		}
	}
	cout << (cnt + 1) / 2;
	
	return 0;
}