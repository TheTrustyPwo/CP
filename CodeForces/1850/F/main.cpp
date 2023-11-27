#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int cnt[n+1]; fill(cnt, cnt + n + 1, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x <= n) cnt[x]++;
    }
    int dp[n+1]; fill(dp, dp + n + 1, 0); dp[0] = 0;
    for (int i = 1; i <= n; i++) for (int j = i; j <= n; j += i) dp[j] += cnt[i];
    cout << *max_element(dp, dp + n + 1) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
