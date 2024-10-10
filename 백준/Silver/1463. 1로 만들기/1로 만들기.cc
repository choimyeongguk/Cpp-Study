#include <bits/stdc++.h>
using namespace std;

int func(int x) {
	if(x <= 1) return 0;
	int a = func(x/3) + x%3 + 1;
	int b = func(x/2) + x%2 + 1;
	return a < b ? a : b;
}

int main() {
	int N;
	
	cin >> N;
	cout << func(N);
	
	return 0;
}

//int main() {
//	int N, num, order, tmp;
//	queue<pair<int,int>> bfs;  // 숫자, 연산 횟수 
//	vector<bool> visited;
//	
//	cin >> N;
//	bfs.push({ N, 0 });
//	visited.assign(N + 1, false);
//	visited[N] = true;
//	while(!bfs.empty()) {
//		num = bfs.front().first;
//		order = bfs.front().second + 1;
//		if(num == 1) {
//			cout << order - 1;
//			break;
//		}
//		bfs.pop();
//		
//		tmp = num / 3;
//		if(!(num % 3) && !visited[tmp]) {
//			bfs.push({ tmp, order });
//			visited[tmp] = true;
//		}
//		
//		tmp = num / 2;
//		if(!(num % 2) && !visited[tmp]) {
//			bfs.push({ tmp, order });
//			visited[tmp] = true;
//		}
//		
//		tmp = num - 1;
//		if(!visited[tmp]) {
//			bfs.push({ tmp, order });
//			visited[tmp] = true;
//		}
//	}
//	
//	return 0;
//}