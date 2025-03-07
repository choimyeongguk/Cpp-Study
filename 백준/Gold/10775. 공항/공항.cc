#include <bits/stdc++.h>
using namespace std;

int tree[100001];

int pa(int x) {
	if(x == tree[x]) return x;
	return tree[x] = pa(tree[x]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int G, P, g, ans = 0, i;
	
	cin >> G >> P;
	for(i = 1; i <= G; i++) tree[i] = i;
	for(i = 0; i < P; i++) {
		cin >> g;
		g = pa(g);
		// 게이트 사용 전에는 모두 자신의 부모는 자신의 번호
		// 하지만 사용하면 책임을 자신의 전 번호 게이트에 떠넘김
		// 결국 1번 게이트마저 책임을 떠넘겨 1번 게이트의 부모가 0이 되면 종료 
		if(!tree[g]) break;
		else tree[g]--, ans++;
	}
	cout << ans;
	
	return 0;
}