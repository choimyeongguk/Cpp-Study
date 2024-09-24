#include <bits/stdc++.h>
using namespace std;

int main() {
	int chk, i;
	string word;
	
	while(1) {
		cin >> word;
		if(word == "0") {
			break;
		}
		chk = 0;
		for(i = 0; i < word.length()/2; i++) {
			if(word[i] != word[word.length()-1-i]) {
				chk = 1;
				break;
			}
		}
		cout << (chk==0 ? "yes" : "no") << '\n';
	}
	
	return 0;
}