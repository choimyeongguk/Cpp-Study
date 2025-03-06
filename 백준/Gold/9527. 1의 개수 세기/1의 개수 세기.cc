#include <bits/stdc++.h>
using namespace std;

long long A, B;
long long oneCnt[55];

// 1 ~ x까지의 1 누적 개수 
long long calculate(long long x) {
	long long ret = x & 1;
	
	// 만약 x의 최상위 비트가 6자리라면, 5자리까지의 누적합 더해준 후,
	// (x - 100000(2)) 만큼 1의 개수 더해줌
	// 그러면 남는 건 1부터 시작하는 다섯 자리 숫자들의 모음
	// x 없어질 때까지 같은 작업 반복 
	for (int i = 54; i > 0; i--) {
		if (x & (1LL << i)) {
			ret += oneCnt[i - 1] + (x - (1LL << i) + 1);
			x -= 1LL << i;
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	
	oneCnt[0] = 1;	// 1 ~ 2^0 까지의 1 누적 개수 
	for (long long i = 1; i < 55; i++)
		oneCnt[i] = oneCnt[i - 1] * 2 + (1LL << i);

	cin >> A >> B;
	cout << calculate(B) - calculate(A - 1);

	return 0;
}