#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    pair<int, int> a[n]; for (int i = 0; i < n; i++) { cin >> a[i].first; a[i].second = i; }
    sort(a, a + n);
    int ans[n]; int cur = 0, reached = -1;
    for (int i = 0; i < n; i++) {
        if (reached < i) {
            cur += a[i].first;
            for (int j = reached + 1; j < n; j++) {
                if (j == i) { reached = j; continue; }
                if (cur >= a[j].first) cur += a[j].first, reached = j;
                else break;
            }
        }
        ans[a[i].second] = reached;
    }
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
