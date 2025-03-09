#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pll;

pll A, B, C, D;

int ccw(pll p1, pll p2, pll p3) {
	long long ret = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
	ret -= p1.second * p2.first + p2.second * p3.first + p3.second * p1.first;
	return ret == 0 ? 0 : ret > 0 ? 1 : -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int ret = 0;

	cin >> A.first >> A.second >> B.first >> B.second;
	cin >> C.first >> C.second >> D.first >> D.second;

	if (A > B) swap(A, B);
	if (C > D) swap(C, D);

	int l1 = ccw(A, B, C) * ccw(A, B, D);
	int l2 = ccw(C, D, A) * ccw(C, D, B);

	if (l1 == 0 && l2 == 0) {
		if (A <= D && C <= B)
			ret = 1;
	}
	else {
		if (l1 <= 0 && l2 <= 0)
			ret = 1;
	}

	cout << ret;

	return 0;
}