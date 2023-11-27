#include <bits/stdc++.h>
using namespace std;
#define int long long
const int m = 998244353;

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    int res = 0;
    for (int b = 0; b < 30; b++) {
        int cur = 0;
        vector<int> cnt(2), sum(2);
        int x = 0; cnt[0] = 1;
        for (int i = 0; i < n; i++) {
            x ^= ((a[i] >> b) & 1);
            int r = (cnt[x ^ 1] * (i + 1)) % m;
            int s = (r - sum[x ^ 1] + m) % m;
            cur = (cur + s) % m;
            cnt[x]++;
            sum[x] = (sum[x] + i + 1) % m;
        }
        res += (cur * (1 << b)) % m; res %= m;
    } cout << res << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= 1; i++) test_case(i);
    return 0;
}
