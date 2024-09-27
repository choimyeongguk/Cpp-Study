#include <bits/stdc++.h>
using namespace std;

typedef struct {
	int w;
	int h;
	int order;
	int bigger;
} BUILD;

bool compare1(BUILD& a, BUILD& b) {
	return a.w < b.w;
}

bool compare2(BUILD& a, BUILD& b) {
	return a.order < b.order;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, w, h, bigger, i, j;
	vector<BUILD> S;
	
	cin >> N;
	S.resize(N);
	for(i = 0; i < N; i++) {
		cin >> w >> h;
		S[i] = { w, h, i, 0 };
	}
	sort(S.begin(), S.end(), compare1);
	for(i = 0; i < N; i++) {
		bigger = 0;
		for(j = i + 1; j < N; j++) {
			if(S[i].w < S[j].w && S[i].h < S[j].h) {
				bigger++;
			}
		}
		S[i].bigger = bigger + 1;
	}
	sort(S.begin(), S.end(), compare2);
	for(i = 0; i < N; i++) {
		cout << S[i].bigger << ' ';
	}
	
	return 0;
}