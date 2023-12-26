#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    string s; cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') cnt0++;
        else cnt1++;
    }

    int idx = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            if (cnt1 == 0) { idx = i; break; }
            cnt1--;
        } else {
            if (cnt0 == 0) { idx = i; break; }
            cnt0--;
        }
    }

    if (idx == -1) { cout << 0 << '\n'; return; }
    cout << s.size() - idx << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
