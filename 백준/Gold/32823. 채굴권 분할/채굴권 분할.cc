#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using vvll = vector<vector<ll>>;
using ld = long double;
const ll mod = 1000000007;

int solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
}

int solve() {
    int n, i;
    ld p0_d, p0_r;
    ld p1_d, p1_l;
    ld p2_d, p2_l;
    vector<pair<ld,ld>> line;

    cin >> n;
    line.resize(n);
    for(i = 0; i < n; i++) {
        cin >> line[i].first >> line[i].second;
    }
    cin >> p1_d >> p1_l;
    cin >> p2_d >> p2_l;

    int ans = 0;
    ld pi = 3.14159265358979;
    for(i = 0; i < n; i++) {
        ld p0_d = (line[i].first + line[i].second) / 2.0;
        ld p0_l = 2000 * cos((pi/1800) * abs(line[i].first - line[i].second) / 2);
        ld l = p1_l * p1_l + p0_l * p0_l - 2 * p1_l * p0_l * cos((pi/1800) * abs(p0_d - p1_d));
        int cnt = 0;
        if(l >= p1_l * p1_l) cnt++;
        else cnt--;

        l = p2_l * p2_l + p0_l * p0_l - 2 * p2_l * p0_l * cos((pi/1800) * abs(p0_d - p2_d));
        if (l >= p2_l * p2_l) cnt++;
        else cnt--;

        if (cnt == 2 || cnt == -2)
            continue;
        else 
            ans++;
    }
    if(ans % 2 == 1) {
        cout << "NO";
    } else {
        cout << "YES";
    }

    return 0;
}

/*
3
450 1800
900 0
450 2700
900 850
450 500

4
450 1800
0 1350
1350 2700
2700 0
450 500
3150 950
*/