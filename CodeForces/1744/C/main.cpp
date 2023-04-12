#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; char c; cin >> n >> c;
    string s; cin >> s;
    int k = -1, ans = 0; s += s;
    for (int i = s.size(); i >= 0; i--) {
        if (s[i] == 'g') k = i;
        if (s[i] == c) ans = max(ans, k - i);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
