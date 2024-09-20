#include <bits/stdc++.h>
using namespace std;

int main()
{
	int cnt = 0, n, i;
	char remainder[42] = { 0 };
	
	for(i=0; i<10; i++)
	{
		cin >> n;
		if(remainder[n%42]++ == 0)
		{
			cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}