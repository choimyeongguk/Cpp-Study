#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n = 0, tmp, i;
	
	for(i=0; i<5; i++)
	{
		cin >> tmp;
		n += tmp * tmp;
	}
	n %= 10;
	cout << n;
	
	return 0;
}