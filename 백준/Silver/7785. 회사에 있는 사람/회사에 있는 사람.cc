#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	string name, state;
	set<string, greater<string>> log;
	
	cin >> n;
	while(n--) {
		cin >> name >> state;
		auto it = log.find(name);
		if(it == log.end()) {
			log.insert(name);
		}
		else {
			log.erase(it);
		}
	}
	for(auto& e : log) {
		cout << e << "\n";
	}
	
	return 0;
}