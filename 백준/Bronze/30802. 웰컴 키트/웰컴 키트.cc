#include <bits/stdc++.h>
using namespace std;

int main() {
	int i;
	int N, T, P;
	int bundle = 0;
	int num[6];
	
	cin >> N;
	for(i = 0; i < 6; i++) {
		cin >> num[i];
	}
	cin >> T >> P;
	
	for(int e : num) {
		if(e > 0) {
			bundle += (e-1)/T + 1;
		}
	}
	cout << bundle << '\n';
	cout << N/P << ' ' << N%P;
	
	return 0;
}