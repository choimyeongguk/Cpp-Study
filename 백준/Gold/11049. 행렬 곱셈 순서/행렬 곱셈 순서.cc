#include <bits/stdc++.h>
using namespace std;

vector<int> len;
int memo[501][501] = { 0 };
// 행렬의 곱셈 [a * b][b * c][c * d]...는 a b c...의 수열로 나타낼 수 있음 
// dp[i][j] = k : i번 부터 j번 값의 연산 횟수의 최솟값 k 

int getCalcMin(int s, int e) {
	if(memo[s][e] != 0) return memo[s][e];
	int tmp, i;
	int ret = len[s] * len[s + 1] * len[e] + getCalcMin(s + 1, e);
	for(i = s + 2; i < e - 1; i++) {
		tmp = len[s] * len[i] * len[e] + getCalcMin(s, i) + getCalcMin(i, e);
		ret = min(ret, tmp);
	}
	ret = min(ret, len[s] * len[e - 1] * len[e] + getCalcMin(s, e - 1));
	return memo[s][e] = ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, a, b, i;
	
	cin >> N >> a >> b;
	len.push_back(a);
	len.push_back(b);
	for(i = 1; i < N; i++) {
		cin >> a >> b;
		len.push_back(b);
	}
	for(i = 2; i <= N; i++) {
		memo[i - 2][i] = len[i - 2] * len[i - 1] * len[i];
	}
	
	cout << getCalcMin(0, N); 
	
	return 0;
}