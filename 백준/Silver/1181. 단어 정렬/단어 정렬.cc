#include <bits/stdc++.h>
using namespace std;

//bool compare(string a, string b) {
//	if(a.length() == b.length()) {
//		return a < b;
//	}
//	return a.length() < b.length();
//}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	vector<string> word(N);
	for(auto& e : word) {
		cin >> e;
	}
	
	sort(word.begin(), word.end(), [](string& a, string& b) {
		if(a.size() == b.size()) {
			return a < b;
		}
		return a.size() < b.size();
	});
	
	cout << word[0] << '\n';
	for(int i = 1; i < N; i++) {
		if(word[i-1] != word[i]) {
			cout << word[i] << '\n';
		}
	}
	
	return 0;
}