#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    char ch[n + 1]; for (int i = 1; i <= n; i++) cin >> ch[i];

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            if (ch[j] == '1') break;
            if (ch[j] == '.') continue;
            ans += i;
            ch[j] = '.';
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
