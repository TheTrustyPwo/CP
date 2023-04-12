#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n, m; cin >> n >> m;
    int a[m]; for (int i = 0; i < m; i++) cin >> a[i];

    int nearest[n + 1];
    for (int i = a[0]; i >= 0; i--) nearest[i] = a[0] - i;
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j <= (a[i + 1] - a[i]) / 2; j++) nearest[j + a[i]] = j;
        for (int j = (a[i + 1] - a[i]) / 2 + 1; j < a[i + 1]; j++) nearest[j + a[i]] = a[i + 1] - a[i] - j;
    }
    for (int i = a[m - 1]; i <= n; i++) nearest[i] = i - a[m - 1];

    int mx = *max_element(nearest + 1, nearest + n);
    cout << n - mx - 1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
