#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int G, P, g, ans = 0, i, j;
	vector<int> dock;
	
	cin >> G >> P;
	for(i = 1; i <= G; i++)
		dock.emplace_back(i);
	for(i = 0; i < P; i++) {
		cin >> g;
		auto it = upper_bound(dock.begin(), dock.end(), g);
		if(it == dock.begin()) break;
		else {
			dock.erase(it - 1);
			ans++;
		}
	}
	cout << ans;
	
	return 0;
}