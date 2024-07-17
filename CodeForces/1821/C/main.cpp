#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    string s; cin >> s;
    int mn = 1e9;
    for (int i = 0; i < 26; i++) {
        int cur = 0, idx = 0;
        for (int j = 0; j <= s.size(); j++) {
            if (j == s.size() || s[j] - 'a' == i) {
                cur = max(cur, (j - idx + 1) / 2), idx = j;
            }
        }
        // cout << i << ' ' << cur << '\n'; 
        mn = min(mn, cur);
    }
    cout << mn << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
