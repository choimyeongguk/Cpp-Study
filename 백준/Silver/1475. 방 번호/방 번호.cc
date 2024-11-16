#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, tmp, max, i;
	int freq[9] = { 0 };
	
	cin >> N;
	while(N) {
		tmp = N % 10;
		N /= 10;
		if(tmp == 9)
			tmp = 6;
		freq[tmp]++;
	}
	freq[6] = (freq[6] + 1) / 2;
	for(max = 0, i = 0; i <= 8; i++)
		max = max > freq[i] ? max : freq[i];
	cout << max;
	
	return 0;
}