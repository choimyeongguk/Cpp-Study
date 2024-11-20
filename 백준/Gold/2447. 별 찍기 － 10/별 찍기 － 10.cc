#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<char>> image;

void solve(int r, int c, int s) {
	if(s == 3) {
		image[r][c] = image[r][c + 1] = image[r][c + 2] = '*';
		image[r + 1][c] = image[r + 1][c + 2] = '*';
		image[r + 2][c] = image[r + 2][c + 1] = image[r + 2][c + 2] = '*';
		return;
	}
	s /= 3;
	solve(r, c, s);
	solve(r, c + s, s);
	solve(r, c + s + s, s);
	solve(r + s, c, s);
	solve(r + s, c + s + s, s);
	solve(r + s + s, c, s);
	solve(r + s + s, c + s, s);
	solve(r + s + s, c + s + s, s);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	image.assign(N, vector<char>(N, ' '));
	solve(0, 0, N);
	for(auto& r : image) {
		for(auto& c : r) {
			cout << c;
		}
		cout << "\n";
	}
	
	return 0;
}