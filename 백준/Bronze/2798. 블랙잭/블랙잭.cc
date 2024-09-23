#include <bits/stdc++.h>
using namespace std;

int main() {
	int i, j, k;
	int N, M, max = 0, sum;
	int* card;
	
	cin >> N >> M;
	card = (int*)calloc(N, sizeof(int));
	for(i = 0; i < N; i++) {
		cin >> card[i];
	}
	sort(card, card + N, greater<>());
	for(i = 0; i < N; i++) {
		for(j = i+1; j < N; j++) {
			for(k = j+1; k < N; k++) {
				sum = card[i] + card[j] + card[k];
				if(sum <= M) {
					if(sum >= max) {
						max = sum;
					}
					else break;
				}
			}
		}
	}
	cout << max;
	
	free(card);
	return 0;
}