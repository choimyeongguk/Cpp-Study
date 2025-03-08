#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, i;
	string name;
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> name;
		for(auto& e : name) {
			if(e < 'a') e += 32;
		}
		cout << name << "\n";
	}
	
	return 0;
}