#include <bits/stdc++.h>
using namespace std;

int L, C;
string S;
string pwd;

void solve(int depth) {
	if(pwd.size() == L) {
		int vowel = 0, consonant = 0;
		for(auto& c : pwd) {
			if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				vowel++;
			else
				consonant++;
			if(vowel != 0 && consonant >= 2) {
				cout << pwd << "\n";
				break;
			}
		}
		return;
	}
	for(int i = depth; i < C; i++) {
		pwd.push_back(S[i]);
		solve(i + 1);
		pwd.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int i;
	
	cin >> L >> C;
	S.resize(C);
	for(i = 0; i < C; i++)
		cin >> S[i];
	sort(S.begin(), S.end());

	solve(0);
	
	return 0;
}