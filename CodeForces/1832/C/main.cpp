#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 1;
    int state = 2; // INC - 0, DEC - 1
    for (int i = 1; i < n; i++) {
        int newState = 2;
        if (a[i] > a[i - 1]) newState = 0;
        else if (a[i] < a[i - 1]) newState = 1;
        if (state != newState && newState != 2) {
            ans++;
            state = newState;
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
