#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, i;
	int l[100001];
	int p[100001];
	long long min, ans = 0;
	
	cin >> N;
	for(i = 1; i < N; i++)
		cin >> l[i];
	for(i = 0; i < N; i++)
		cin >> p[i];
	
	min = p[0];
	for(i = 1; i < N; i++) {
		ans += l[i] * min;
		if(min > p[i])
			min = p[i];
	}
	cout << ans;
	
	return 0;
}