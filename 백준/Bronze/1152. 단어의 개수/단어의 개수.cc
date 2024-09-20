#include <bits/stdc++.h>
using namespace std;

int main()
{
	int idx = 0, cnt = 0;
	string S;
	
	getline(cin, S);
	while(S[++idx] != '\0')
	{
		if(S[idx] == ' ')
			cnt++;
	}
	if(S[idx-1] == ' ')
		cnt--;
	cout << cnt + 1;
	
	return 0;
}