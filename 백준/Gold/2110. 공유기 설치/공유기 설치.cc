#include <bits/stdc++.h>
using namespace std;

int N, C, ans = 0;
int x[200001];

bool canMake(int d) {
	int numC = C - 1, house = 0;	// x[0]에 설치 
	for(int i = 1; i < N && numC > 0; i++) {
		if(x[i] - x[house] >= d) {
			house = i;
			numC--;
		}
	}
	if(numC)
		return false;
	return true;
}

void binarySearch(int s, int e) {
	if(s <= e) {
		int m = (s + e) / 2;
		if(canMake(m)) {
			ans = m;
			binarySearch(m + 1, e);
		}
		else {
			binarySearch(s, m - 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> C;
	for(int i = 0; i < N; i++) {
		cin >> x[i];
	}
	sort(x, x + N);
	binarySearch(1, x[N - 1] - x[0]);
	cout << ans;
	
	return 0;
}