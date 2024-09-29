#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T, N, M, w, cnt, i;
	int freq[10] = { 0 };
	bool chk;
	queue<pair<int, int>> printer;
	
	cin >> T;
	while(T--) {
		cin >> N >> M;
		for(i = 0; i < N; i++) {
			cin >> w;
			printer.push({ w, i });
			freq[w]++;
		}
		
		cnt = 0;
		while(true) {
			chk = true;
			for(i = printer.front().first + 1; i < 10; i++) {
				if(freq[i]) {
					chk = false;	// 중요도 높은 문서 존재 
					break;
				}
			}
			if(chk == false) {
				printer.push(printer.front());
				printer.pop();
				continue;
			}
			cnt++;
			if(printer.front().second == M) {
				cout << cnt << '\n';
				break;
			}
			freq[printer.front().first]--;
			printer.pop();
			
		}
		
		while(!printer.empty()) printer.pop();
		memset(freq, 0, sizeof(freq));
	}
	
	return 0;
}