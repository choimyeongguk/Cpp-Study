#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, tmp;
	
	while(1)
	{
		cin >> a >> b >> c;
		if(a==0 && b==0 && c==0)
			break;
			
		if(b > a)
		{
			tmp = a;
			a = b;
			b = tmp;
		}
		if(c > a)
		{
			tmp = a;
			a = c;
			c = tmp;
		}
		if(a*a == b*b + c*c)
			cout << "right" << '\n';
		else
			cout << "wrong" << '\n';
	}
	
	return 0;
}