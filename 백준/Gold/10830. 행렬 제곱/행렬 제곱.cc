#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> A;
map<long long,vector<vector<int>>> memo;

vector<vector<int>> multiple(const vector<vector<int>> X, const vector<vector<int>> Y) {
	vector<vector<int>> ret(N, vector<int>(N, 0));
	for(int r = 0; r < N; r++) {
		for(int c = 0; c < N; c++) {
			for(int i = 0; i < N; i++) {
				ret[r][c] += X[r][i] * Y[i][c];
			}
			ret[r][c] %= 1000;
		}
	}
	return ret;
}

vector<vector<int>> power(long long B) {
	if(memo.find(B) != memo.end()) {
		return memo[B];
	}
	vector<vector<int>> ret;
	vector<vector<int>> tmp = power(B / 2);
	if(B % 2 == 0)  // 짝수 
		ret = multiple(tmp, tmp);
	else  			// 홀수 
		ret = multiple(multiple(tmp, tmp), A);
	memo.insert({B, ret});
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long B;
	vector<vector<int>> ans;
	
	cin >> N >> B;
	A.resize(N, vector<int>(N));
	for(auto& r : A) {
		for(auto& c : r) {
			cin >> c;
			c %= 1000;
		}
	}
	memo.insert({1, A});
	ans = power(B);
	for(auto& r : ans) {
		for(auto& c : r) {
			cout << c << " ";
		}
		cout << "\n";
	}
	
	return 0;
}