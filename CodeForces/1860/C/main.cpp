#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int ans = 0;
    int mn = n + 1, mnWin = n + 1;
    while (n--) {
      int x; cin >> x;
      if (mn < x && x < mnWin) {
        ans++;
        mnWin = x;
      }
      mn = min(mn, x);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
