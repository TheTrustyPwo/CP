#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int b[n]; for (int i = 0; i < n; i++) cin >> b[i];

    pair<int, int> tmp[n]; for (int i = 0; i < n; i++) tmp[i] = {a[i] + b[i], i};
    sort(tmp, tmp + n, greater<pair<int, int>>());

    bool turn = 1; 
    for (int k = 0; k < n; k++) {
        int idx = tmp[k].second;
        if (turn) {
            a[idx] -= 1;
            b[idx] = 0;
        } else {
            a[idx] = 0;
            b[idx] -= 1;
        } turn = !turn;
    }

    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) s1 += a[i], s2 += b[i];
    cout << s1 - s2 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
