#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	bool chk;
	int T, i;
	int freq1[26], freq2[26];
	string str1, str2;
	
	cin >> T;
	while(T--) {
		cin >> str1 >> str2;
		
		for(i = 0; i < 26; i++) {
			freq1[i] = 0;
			freq2[i] = 0;
		}
		for(auto& e : str1) {
			freq1[e - 'a']++;
		}
		for(auto& e : str2) {
			freq2[e - 'a']++;
		}
		
		for(chk = true, i = 0; i < 26; i++) {
			if(freq1[i] != freq2[i]) {
				chk = false;
				break;
			}
		}
		cout << (chk ? "Possible" : "Impossible") << "\n";
	}
	
	return 0;
}