#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, num, sum = 0, i;
	
	cin >> N;
	getchar();
	for(i=0; i<N; i++)
	{
		sum += getchar() - '0';
	}
	cout << sum;
	
	return 0;
}