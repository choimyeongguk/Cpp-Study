#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	char c;
	int N, K, i;
	string st;
	
	cin >> N >> K;
	for(i = 0; i < N; i++) {
		cin >> c;
		while(!st.empty() && st.back() < c && K > 0) {
			st.pop_back();
			K--;
		}
		st += c;
	}
	while(K--) st.pop_back();
	cout << st;
	
	return 0;
}