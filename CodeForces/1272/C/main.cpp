#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, k; cin >> n >> k; string s; cin >> s;
    unordered_set<char> ch;
    for (int i = 0; i < k; i++) {
        char c; cin >> c;
        ch.insert(c);
    }

    int ans = 0, cur = 0;
    for (int i = 0; i <= n; i++) {
        if (i == n || ch.find(s[i]) == ch.end()) {
            ans += (cur * (cur + 1)) / 2;
            cur = 0;
        } else cur++;
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= 1; i++) test_case(i);
    return 0;
}
