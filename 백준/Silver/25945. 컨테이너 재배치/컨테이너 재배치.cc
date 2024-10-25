#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, h, hp, ans, i;
	vector<int> container;
	
	cin >> n;
	container.resize(n);
	for(m = 0, i = 0; i < n; i++) {
		cin >> container[i];
		m += container[i];
	}
	h = m / n;
	hp = m % n;  // 높은 기둥 개수
	ans = 0;
	for(i = 0; i < n; i++) {
		if(container[i] > h) {
			if(hp) {
				ans += container[i] - h - 1;
				hp--;
			} else {
				ans += container[i] - h;
			}
		}
	}
	cout << ans;
	
	return 0;
}