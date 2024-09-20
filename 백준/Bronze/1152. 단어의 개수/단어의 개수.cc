#include <bits/stdc++.h>
using namespace std;

int main()
{
	int cnt = 0, i;
	char prev, s;
	
	prev = getchar();
	while((s=getchar()) != '\n')
	{
		if(s == ' ')
			cnt++;
		prev = s;
	}
	if(prev == ' ')
		cnt--;
	cout << cnt + 1;
	
	return 0;
}