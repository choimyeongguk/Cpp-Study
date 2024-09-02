#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T, R, i, j, k;
	char S[21];
	
	cin >> T;
	for(i=0; i<T; i++)
	{
		cin >> R >> S;
		for(j=0; S[j]!='\0'; j++)
		{
			for(k=0; k<R; k++)
			{
				cout << S[j];
			}
		}
		cout << '\n';
	}
	
	return 0;
}