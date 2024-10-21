#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	bool status = true;
	int ans = 0;
	char c;
	string number = "";
	
	while((c = getchar()) != '\n') {
		if('0' <= c && c <= '9') {
			number += c;
		} else {
			ans += status ? stoi(number) : -stoi(number);
			number = "";
			if(c == '-') {
				status = false;
			}
		}
	}
	ans += status ? stoi(number) : -stoi(number);
	cout << ans;
	
	return 0;
}