#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
	if(a.length() == b.length()) {
		return a < b;
	}
	return a.length() < b.length();
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	string word[20001];
	
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> word[i];
	}
	sort(word, word + N, compare);
	for(int i = 0; i < N; i++) {
		if(word[i] != word[i+1]) {
			cout << word[i] << '\n';
		}
	}
	
	return 0;
}