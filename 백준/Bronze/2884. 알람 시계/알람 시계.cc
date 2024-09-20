#include <bits/stdc++.h>
using namespace std;

int main()
{
	int H, M;
	
	cin >> H >> M;
	M -= 45;
	if(M < 0)
	{
		M += 60;
		H = H==0 ? 23 : H-1;
	}
	cout << H << ' ' << M;
	
	return 0;
}