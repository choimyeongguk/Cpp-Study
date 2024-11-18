#include <bits/stdc++.h>
using namespace std;

int main() {
	long long S, i;
	
	cin >> S;
	for(i = 1; S >= 0; i++)
		S -= i;
	cout << i - 2;
	
	return 0;
}