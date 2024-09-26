#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, tmp, i, j;
	int frequency[10001] = { 0 };
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> tmp;
		frequency[tmp]++;
	}
	for(i = 1; i <= 10000; i++) {
		for(j = 0; j < frequency[i]; j++) {
			cout << i << '\n';
		}
	}
	
	return 0;
}