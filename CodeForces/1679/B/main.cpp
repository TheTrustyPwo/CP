#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, q; cin >> n >> q;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) cin >> a[i].first;
    int sum = 0; for (int i = 0; i < n; i++) sum += a[i].first, a[i].second = 0;
    pair<int, int> last = make_pair(-1, -1);
    for (int j = 1; j <= q; j++) {
        int t, i, x; cin >> t;
        if (t == 1) {
            cin >> i >> x; i--;
            int cur = (last.second > a[i].second ? last.first : a[i].first);
            sum += x - cur;
            a[i] = make_pair(x, j);
            cout << sum << '\n';
        } else {
            cin >> x;
            sum = x * n;
            last = make_pair(x, j);
            cout << sum << '\n';
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= 1; i++) test_case(i);
    return 0;
}
