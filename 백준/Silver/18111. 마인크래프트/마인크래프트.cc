#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, B, maxH, minH, put, rmv, ans, T, minT, i;
	vector<int> h;
	
	cin >> N >> M >> B;
	
	maxH = B;
	minH = 0x3f3f3f3f;
	N *= M;
	h.resize(N);
	for(auto& e : h) {
		cin >> e;
		maxH += e;
		minH = minH < e ? minH : e;
	}
	maxH /= N;
	
	minT = 0x3f3f3f3f;
	for(i = maxH; i >= minH; i--) {
		put = 0, rmv = 0;
		for(auto& e : h) {
			if(e > i) rmv += e - i;
			else put += i - e;
		}
		T = put + rmv * 2;
		if(minT > T) {
			minT = T;
			ans = i;
		}
	}
	cout << minT << " " << ans;
	
	return 0;
}