#include <bits/stdc++.h>
using namespace std;
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();
    int n; cin >> n;
    int dp[n], a[n]; arrPut(a);

    dp[0] = 1;
    range(i, 1, n) {
        dp[i] = (i + 1) * (i + 1);
        range(j, 0, i) {
            if (a[j] < a[i]) continue;
            dp[i] = min(dp[i], dp[j] + (i - j) * (i - j));
        }
    }

    int ans = dp[0] + n * n;
    range(i, 1, n) {
        ans = min(ans, dp[i] + (n - i) * (n - i));
    }

    cout << ans;
}
