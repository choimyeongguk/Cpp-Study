#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T, H, W, N, i;
	int layer, num;
	
	cin >> T;
	for(i=0; i<T; i++)
	{
		cin >> H >> W >> N;
		layer = N%H==0 ? H : N%H;
		num = N%H==0 ? N/H : N/H+1;
		printf("%d%02d\n", layer, num);
	}
	
	return 0;
}