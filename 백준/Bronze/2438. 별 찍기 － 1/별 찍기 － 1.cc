#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, i, j;
	
	cin >> n;
	for(i=1; i<=n; i++)
	{
		for(j=0; j<i; j++)
		{
			cout << '*';
		}
		cout << endl;
	}
	
	return 0;
}