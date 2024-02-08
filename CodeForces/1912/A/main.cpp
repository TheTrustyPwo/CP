#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int x, k; cin >> x >> k;
    vector<pair<int, int>> lst[k];

    priority_queue<pair<int, pair<int, int>>> pq;

    for (int i = 0; i < k; i++) {
        int n, tmp, sum = 0, mn = 1e9; cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> tmp; sum += tmp; mn = min(mn, sum);
            if (sum > 0) lst[i].push_back({mn, sum}), sum = 0, mn = 1e9;
        }
        if (!lst[i].empty()) pq.push({lst[i][0].first, {i, 0}});
    }

    int ans = x;
    while (!pq.empty()) {
        int v = pq.top().first, l = pq.top().second.first, idx = pq.top().second.second; pq.pop();
        if (x + v < 0) continue;
        x += lst[l][idx].second;
        ans = max(ans, x);
        if (idx < lst[l].size() - 1) pq.push({lst[l][idx + 1].first, {l, idx + 1}});
    }

    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= 1; i++) test_case(i);
    return 0;
}
