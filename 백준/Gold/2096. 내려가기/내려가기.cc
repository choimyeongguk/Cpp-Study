#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, a, b, c, t1, t2, t3, i;
	int dpMax[3], dpMin[3];
	
	cin >> N >> dpMax[0] >> dpMax[1] >> dpMax[2];
	dpMin[0] = dpMax[0], dpMin[1] = dpMax[1], dpMin[2] = dpMax[2];
	for(i = 1; i < N; i++) {
		cin >> a >> b >> c;
		t1 = a + max(dpMax[0], dpMax[1]);
		t2 = b + max(dpMax[0], max(dpMax[1], dpMax[2]));
		t3 = c + max(dpMax[1], dpMax[2]);
		dpMax[0] = t1, dpMax[1] = t2, dpMax[2] = t3;
		t1 = a + min(dpMin[0], dpMin[1]);
		t2 = b + min(dpMin[0], min(dpMin[1], dpMin[2]));
		t3 = c + min(dpMin[1], dpMin[2]);
		dpMin[0] = t1, dpMin[1] = t2, dpMin[2] = t3;
	}
	cout << max(dpMax[0], max(dpMax[1], dpMax[2])) << " " << min(dpMin[0], min(dpMin[1], dpMin[2]));
	
	return 0;
}