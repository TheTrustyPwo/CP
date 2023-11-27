#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, m, d; cin >> n >> m >> d;
    int s[m+1]; s[0] = 1; for (int i = 1; i <= m; i++) cin >> s[i];

    int pre[m+1]; pre[0] = 1, pre[1] = (s[1] == 1 ? 1 : 2 + (s[1] - 2) / d);
    for (int i = 2; i <= m; i++)
        pre[i] = pre[i-1] + 1 + (s[i] - s[i-1] - 1) / d; 

    int suf[m+1]; suf[m] = 1 + (n - s[m]) / d;
    for (int i = m - 1; i >= 0; i--)
        suf[i] = suf[i+1] + 1 + (s[i+1] - s[i] - 1) / d;

    int ans[m+1];
    for (int i = 1; i < m; i++)
        ans[i] = pre[i-1] + suf[i+1] + (s[i+1] - s[i-1] - 1) / d;
    ans[m] = pre[m-1] + (n - s[m-1]) / d;

    int mn = *min_element(ans + 1, ans + m + 1), cnt = 0;
    for (int i = 1; i <= m; i++) if (ans[i] == mn) cnt++;
    cout << mn << ' ' << cnt << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
