#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i, alphabet[26];
	char tmp;
	
	for(i=0; i<26; i++)
		alphabet[i] = -1;

	for(i=0; (tmp=getchar()) != '\n'; i++)
	{
		if(alphabet[tmp-'a'] == -1)
		{
			alphabet[tmp-'a'] = i;
		}
	}
	for(i=0; i<26; i++)
		cout << alphabet[i] << ' ';
		
	return 0;
}