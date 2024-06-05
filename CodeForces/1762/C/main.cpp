#include <bits/stdc++.h>
using namespace std;
#define int long long
const int m = 998244353;

int pre[200005];

void test_case(int test) {
    int n; string s; cin >> n >> s;

    int ans = 0; char cur = '2'; int length = 0;
    for (int i = 0; i < n; i++) {
        if (cur != s[i]) cur = s[i], length = 0;
        length++;
        ans = (ans + pre[length - 1]) % m;
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    pre[0] = 1;
    for (int i = 1; i <= 200005; i++) pre[i] = (pre[i - 1] * 2) % m;
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
