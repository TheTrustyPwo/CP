#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n, m, sum = 0; cin >> n >> m;
    int a[n][m]; string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            a[i][j] = s[j] - '0';
            sum += a[i][j];
        }
    }
    int minn = 1e9;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            int cnt = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
            if (cnt == 0) continue;
            minn = min(minn, max(1, cnt - 1));
        }
    }
    if (sum == 0) cout << "0\n";
    else cout << 1 + sum - minn << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
