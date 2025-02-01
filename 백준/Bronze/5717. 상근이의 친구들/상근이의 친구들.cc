#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int M, W;

    while(true) {
        cin >> M >> W;
        if(M == 0 && W == 0)
            break;
        cout << M + W << "\n";
    }

    return 0;
}
