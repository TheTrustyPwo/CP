#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n, m, k, d; cin >> n >> m >> k >> d;
    int g[n][m]; for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> g[i][j];

    int mnCost[n];
    for (int i = 0; i < n; i++) {
        int dp[m]; dp[0] = 0;
        deque<int> dq; dq.push_back(0); // idx, val
        for (int j = 1; j < m; j++) {
            if (dq.front() < j - d) dq.pop_front();
            dp[j] = dp[dq.front()] + g[i][j] + 1;
            while (!dq.empty() && dp[dq.back()] >= dp[j]) dq.pop_back();
            dq.push_back(dp[j]);
        }
        mnCost[i] = dp[m - 1];
    }

    for (int i = 0; i < n; i++) cout << mnCost[i] << ' '; cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}