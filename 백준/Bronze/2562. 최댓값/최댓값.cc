#include <bits/stdc++.h>

using namespace std;

int main()
{
	int max = 0, num, tmp, i;
	
	for(i=1; i<=9; i++)
	{
		cin >> tmp;
		if(tmp > max)
		{
			max = tmp;
			num = i;
		}
	}
	cout << max << '\n' << num;
	
	return 0;
}