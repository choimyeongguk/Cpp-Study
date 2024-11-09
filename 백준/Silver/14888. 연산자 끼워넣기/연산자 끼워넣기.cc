#include <bits/stdc++.h>
using namespace std;

int N, Max = -0x3f3f3f3f, Min = 0x3f3f3f3f;
int A[12], B[4];
vector<char> op;

void solve() {
	if(op.size() == N - 1) {
		int result = A[0];
		for(int i = 1; i < N; i++) {
			switch(op[i - 1]) {
				case 0 :
					result += A[i];
					break;
				case 1 :
					result -= A[i];
					break;
				case 2 :
					result *= A[i];
					break;
				case 3 :
					result /= A[i];
					break;
			}
		}
		Max = Max > result ? Max : result;
		Min = Min < result ? Min : result;
		return;
	}
	for(int i = 0; i < 4; i++) {
		if(!B[i]) continue;
		op.push_back(i);
		B[i]--;
		solve();
		B[i]++;
		op.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> B[0] >> B[1] >> B[2] >> B[3];
	
	solve();
	cout << Max << "\n" << Min;
	
	return 0;
}