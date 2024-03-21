#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    pair<int, int> a[n], b[n], c[n];
    for (int i = 0; i < n; i++) { cin >> a[i].first; a[i].second = i; }
    for (int i = 0; i < n; i++) { cin >> b[i].first; b[i].second = i; }
    for (int i = 0; i < n; i++) { cin >> c[i].first; c[i].second = i; }

    sort(a, a + n, greater<pair<int, int>>());
    sort(b, b + n, greater<pair<int, int>>());
    sort(c, c + n, greater<pair<int, int>>());

    int ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (a[i].second != b[j].second && b[j].second != c[k].second && a[i].second != c[k].second) {
                    ans = max(ans, a[i].first + b[j].first + c[k].first);
                }
            }
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
