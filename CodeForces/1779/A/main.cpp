#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    string s; cin >> s;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == 'L') cnt1++;
        else cnt2++;
    if (cnt1 == 0 || cnt2 == 0) { cout << -1 << '\n'; return; }
    int fr = 1e9, fl = -1;
    for (int i = 0; i < n; i++)
        if (s[i] == 'L') fl = max(fl, i);
        else fr = min(fr, i);
    if (fr < fl) { cout << 0 << '\n'; return; }
    for (int i = 0; i < n - 1; i++)
        if (s[i] == 'L' && s[i + 1] == 'R') { cout << i + 1 << '\n'; return; }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
