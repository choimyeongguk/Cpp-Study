#include <bits/stdc++.h>
#define MAX 1000000
#define MIN -1000000

using namespace std;

int main()
{
	int N, min = MAX, max = MIN, num, i;
	
	cin >> N;
	for(i=0; i<N; i++)
	{
		cin >> num;
		min = min<num ? min:num;
		max = max>num ? max:num;
	}
	cout << min << ' ' << max;
	
	return 0;
}