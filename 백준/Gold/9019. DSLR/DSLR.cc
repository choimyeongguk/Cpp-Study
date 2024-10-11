#include <bits/stdc++.h>
using namespace std;

int D(int x) {
	return x = (x << 1) % 10000;
}

int S(int x) {
	return x = (x + 9999) % 10000;
}

int L(int x) {
	return x = (x % 1000) * 10 + x / 1000;
}

int R(int x) {
	return x = (x % 10) * 1000 + x / 10;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T, a, b, tmp, i, j;
	vector<bool> visited;
	queue<pair<int,string>> bfs;
	int (*func[4])(int) = {D, S, L, R};
	char funcName[4] = {'D', 'S', 'L', 'R'};
	
	cin >> T;
	for(i = 0; i < T; i++) {
		cin >> a >> b;
		
		visited.assign(10000, false);
		bfs.push({a, ""});
		while(bfs.front().first != b) {
			int& num = bfs.front().first;
			string& cmd = bfs.front().second;
			
			for(j = 0; j < 4; j++) {
				tmp = func[j](num);
				if(!visited[tmp]) {
					visited[tmp] = true;
					bfs.push({tmp, cmd + funcName[j]});
				}
			}
			bfs.pop();
		}
		cout << bfs.front().second << "\n";
		while(!bfs.empty()) bfs.pop();
	}
	
	return 0;
}