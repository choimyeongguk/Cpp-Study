#include <bits/stdc++.h>
using namespace std;

bool num[2000001] = { false };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, tmp, ans = 0, i;
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> tmp;
		num[tmp] = true;
	}
	cin >> M;
	
	tmp = (M + 1) / 2;
	for(i = 1; i < tmp; i++) {
		if(num[i] && num[M - i])
			ans++;
	}
	cout << ans;
	
	return 0;
}