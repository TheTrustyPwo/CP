#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, k, d; cin >> n >> k >> d;
    int a[n + 1], b[n + 1]; set<pair<int, int>> st; int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; b[i] = 0;
        if (a[i] == i) cnt++;
        if (a[i] <= i) st.insert(make_pair(i, a[i]));
    }

    int v[k + 1]; for (int i = 1; i <= k; i++) cin >> v[i];

    int ans = cnt + ((d - 1) / 2);
    for (int i = 1; i <= min(d, 2 * n + 1); i++) {
        for (auto it = st.begin(); it != st.end(); ) {
            pair<int, int> p = *it;
            if (p.first > v[((i - 1) % k) + 1]) break;
            b[p.first]++;
            int val = p.second + b[p.first];

            if (val > p.first) {
                cnt--;
                st.erase(it++);
            } else {
                if (val == p.first) cnt++;
                it++;
            }
        }
        if (d > i) ans = max(ans, cnt + (d - i - 1) / 2);
        if (st.empty()) break;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
