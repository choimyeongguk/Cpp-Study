#include <bits/stdc++.h>
using namespace std;

int N, M;
string ans;

void combr(int depth) {
	if(depth++ == M) {
		cout << ans << "\n";
		return;
	}
	for(int i = 1; i <= N; i++) {
		ans.push_back(i + '0');
		ans.push_back(' ');
		combr(depth);
		ans.pop_back();
		ans.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	combr(0);
	
	return 0;
}