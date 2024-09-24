#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, num, max = 0;
	double avg = 0;
	
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> num;
		avg += num;
		max = max > num ? max : num;
	}
	avg /= N;
	avg *= 100.0/max;
	cout << avg;
	
	return 0;
}