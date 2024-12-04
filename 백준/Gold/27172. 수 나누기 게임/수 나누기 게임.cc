#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, i, j;
	int card[100001];
	int point[1000001] = { 0 };
	bool used[1000001] = { 0 };
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> card[i];
		used[card[i]] = true;
	}
	for(i = 0; i < N; i++) {
		for(j = card[i] << 1; j <= 1000000; j += card[i]) {
			if(used[j]) {
				point[card[i]]++;
				point[j]--;
			}
		}
	}
	for(i = 0; i < N; i++) {
		cout << point[card[i]] << " ";
	}
	
	return 0;
}