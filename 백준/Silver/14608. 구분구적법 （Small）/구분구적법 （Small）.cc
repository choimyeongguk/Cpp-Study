#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

ld K, a, b, N, c[11];
ld delta_x;

ld polynomial(ld x) {
	ld ret = 0;
	for(int i = 0; i <= K; i++) {
		ret += c[i] * pow(x, i);
	}
	return ret;
}

ld get_reimann_sum(ld epsilon) {
	ld ret = 0;
	for(int k = 0; k < N; k++) {
		ret += polynomial(a + k * delta_x + epsilon) * delta_x;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ld integral_sum = 0, reimann_sum, epsilon = -1, tolerance = 0.0001;
	ld l, r, m, err;
	
	cin >> K;
	for(int i = K; i >= 0; i--)
		cin >> c[i];
	cin >> a >> b >> N;
	
	delta_x = (ld)(b - a) / N;
	for(int i = 0; i <= K; i++) {
		integral_sum += (ld)c[i] * (pow(b, i + 1) - pow(a, i + 1)) / (i + 1);
	}	
	
	l = 0, r = delta_x;
	while(r - l > tolerance) {
		m = (l + r) / 2;
		reimann_sum = get_reimann_sum(m);
		err = abs(integral_sum - reimann_sum);
		
		if(err <= tolerance) {
			epsilon = m;
			break;
		}
		else if(reimann_sum < integral_sum)
			l = m;
		else
			r = m;
	}
	cout << epsilon;
	
	return 0;
}