#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int w, n, sum, left, i, j;
	vector<int> A;
	vector<int> idx1(400001, -1);
	vector<int> idx2(400001, -1);
	
	cin >> w >> n;
	A.assign(n, 0);
	for(i = 0; i < n; i++) {
		cin >> A[i];
	}
	for(i = 0; i < n; i++) {
		for(j = i + 1; j < n; j++) {
			sum = A[i] + A[j];
			idx1[sum] = i;
			idx2[sum] = j;
		}
	}
	
	for(i = 0; i < n; i++) {
		for(j = i + 1; j < n; j++) {
			left = w - A[i] - A[j];
			if(left > 400000 || left < 0 || idx1[left] == -1) continue;
			if(idx1[left] != i && idx1[left] != j && idx2[left] != i && idx2[left] != j) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	
	return 0;
}