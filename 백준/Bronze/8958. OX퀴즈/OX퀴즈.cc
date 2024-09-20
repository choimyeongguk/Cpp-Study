#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T, score, accum, i;
	char result;
	
	cin >> T;
	getchar();
	for(i=0; i<T; i++)
	{
		score = 0;
		accum = 0;
		
		while((result=getchar()) != '\n')
		{
			if(result == 'O')
			{
				accum++;
				score += accum;
			}
			else
			{
				accum = 0;
			}
		}
		cout << score << '\n';
	}
}