#include <bits/stdc++.h>
using namespace std;

int main() {
	int cnt = 0;
	string word;
	cin >> word;
	for(int i = 0; i < word.length(); i++) {
		cnt++;
		switch(word[i]) {
			case 'c' : case 's' : case 'z' :
				if(word[i + 1] == '=' || word[i + 1] == '-') i++;
				break;
			case 'd' :
				if(word[i + 1] == 'z' && word[i + 2] == '=') i += 2;
				if(word[i + 1] == '-') i++;
				break;
			case 'l' : case 'n':
				if(word[i + 1] == 'j') i++;
				break;
		}
	}
	cout << cnt;
	return 0;
}