#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, A, B, C, i;
	int cnt[10] = { 0 };
	
	cin >> A >> B >> C;
	N = A * B * C;
	while(N > 0)
	{
		cnt[N%10]++;
		N /= 10;
	}
	for(i=0; i<10; i++)
		cout << cnt[i] << '\n';
	
	return 0;
}