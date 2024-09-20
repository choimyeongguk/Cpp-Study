#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
    ios::sync_with_stdio(false);
	
	int N, X, tmp, i;
	
	cin >> N >> X;
	for(i=0; i<N; i++)
	{
		cin >> tmp;
		if(tmp < X)
			cout << tmp << ' ';
	}
	
	return 0;
}