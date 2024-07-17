#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int low[1000005];

void test_case(int test) {
    int n, m; cin >> n >> m;
    pair<int, int> a[m], b[m];
    for (int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + m);
    deque<pair<int, int>> dq;
    int l = 0;
    for (int i = 1; i <= n; i++) {
        while (dq.front().second < i) dq.pop_front();
        while (a[l].first == i) {
            if (dq.empty() || a[l].second > dq.back().second) dq.push_back(a[l]);
            l++;
        }
        low[i] = dq.front().first;
    }

    
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
