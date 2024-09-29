#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, cut, num, avg = 0, tmp, idx, i;
	int freq[31] = { 0 };
	
	cin >> n;
	if(!n) {
		cout << 0;
		return 0;
	}
	cut = n * 0.15 + 0.5;
	for(i = 0; i < n; i++) {
		cin >> num;
		freq[num]++;
	}
	
	for(tmp = cut, idx = 1; ; idx++) {
		if(freq[idx] >= tmp) {
			freq[idx] -= tmp;
			break;
		} else {
			tmp -= freq[idx];
			freq[idx] = 0;
		}
	}
	for(tmp = cut, idx = 30; ; idx--) {
		if(freq[idx] >= tmp) {
			freq[idx] -= tmp;
			break;
		} else {
			tmp -= freq[idx];
			freq[idx] = 0;
		}
	}
	
	for(i = 1; i <= 30; i++) {
		avg += i * freq[i];
	}
	avg = (double)avg / (n - 2*cut) + 0.5;
	cout << avg;
	
	return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	
//	int n, num, cut, avg = 0, i;
//	vector<int> level;
//	
//	cin >> n;
//	if(!n) {
//		cout << 0;
//		return 0;
//	}
//	cut = n * 0.15 + 0.5;
//	level.assign(n, 0);
//	for(i = 0; i < n; i++) {
//		cin >> num;
//		level[i] = num;
//	}
//	sort(level.begin(), level.end());
//	for(i = cut; i < n-cut; i++) {
//		avg += level[i];
//	}
//	avg = (double)avg / (n - 2*cut) + 0.5;
//	cout << avg;
//	
//	return 0;
//}