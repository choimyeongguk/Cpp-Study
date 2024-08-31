#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b;
	while((a = getchar()) != EOF)
	{
		getchar();
		a -= '0';
		b = getchar() - '0';
		getchar();
		
		cout << a+b << endl;
	}
	
	return 0;
}