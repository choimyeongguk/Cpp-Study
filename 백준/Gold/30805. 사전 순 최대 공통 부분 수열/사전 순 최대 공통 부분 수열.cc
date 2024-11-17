#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	bool chk;
	int N, M, i, j;
	vector<int> A, B, ans;
	
	cin >> N;
	A.resize(N);
	for(auto& e : A)
		cin >> e;
	
	cin >> M;
	B.resize(M);
	for(auto& e : B)
		cin >> e;
	
	while(true) {
		auto A_max = max_element(A.begin(), A.end());
		auto B_max = max_element(B.begin(), B.end());
		
		if(*A_max > *B_max)
			A.erase(A_max);
		else if(*A_max < *B_max)
			B.erase(B_max);
		else {
			ans.push_back(*A_max);
			A.erase(A.begin(), A_max + 1);
			B.erase(B.begin(), B_max + 1);
		}
		if(A.empty() || B.empty())
			break;
	}
	
	cout << ans.size() << "\n";
	if(ans.size())
		for(auto& e : ans)
			cout << e << " ";
	
	
	return 0;
}