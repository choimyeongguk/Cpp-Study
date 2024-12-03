#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int A, B, i;
	unordered_set<int> used;
	
	cin >> A >> B;
	A += B;
	for(i = 0; i < A; i++) {
		cin >> B;
		if(used.find(B) != used.end()) {
			used.erase(B);
		}
		else {
			used.insert(B);
		}
	}
	cout << used.size();
	
	return 0;
}