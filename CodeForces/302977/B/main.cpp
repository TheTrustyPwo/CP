#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, k; cin >> n >> k; string s; cin >> s;
    bool work[26]{};
    for (int i = 0; i < k; i++) {
        char ch; cin >> ch;
        work[ch - 'a'] = 1;
    }

    int cur = 0, ans = 0;
    for (int i = 0; i <= n; i++) {
        if (i == n || !work[s[i] - 'a']) {
            ans += (cur * (cur + 1)) / 2;
            cur = 0;
        } else cur++;
    }

    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= 1; i++) test_case(i);
    return 0;
}
