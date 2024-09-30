#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int M, S = 0x00, x, i;
	string cmd;

	cin >> M;
	for(i = 0; i < M; i++) {
		cin >> cmd;
		
		switch(cmd[0]) {
			case 'a' :
				if(cmd[1] == 'd') {		// add
					cin >> x;
					S |= 1 << (x-1);
				} else {				// all
					S |= 0xFFFFF;
				}
				break;
				
			case 'r' :					// remove
				cin >> x;
				S &= 0xFFFFF - (1 << (x-1));
				break;
			
			case 'c' :					// check
				cin >> x;
				cout << (S >> (x-1) & 0x01) << '\n';
				break;
				
			case 't' :					// toggle
				cin >> x;
				S ^= 1 << (x-1);
				break;
				
			case 'e' :					// empty
				S &= 0;
				break;
		}
	}
	
	return 0;
}