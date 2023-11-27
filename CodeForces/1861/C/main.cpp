#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    string s; cin >> s; int n = s.size();
    int sort = -1, cnt = 0, tot = 0, mn = 0; bool b = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '+') cnt++, tot++;
        else if (s[i] == '-') cnt--, tot--, mn = min(mn, cnt);
        else if (s[i] == '0') {
            if ((sort == 1 && cnt <= 0 && mn >= 0) || tot < 2) b = 0;
            sort = 0, cnt = 0, mn = 0;
        } else {
            if (sort == 0 && cnt >= 0 && mn >= 0) b = 0;
            sort = 1, cnt = 0, mn = 0;
        }
    }
    cout << (b ? "YES\n" : "NO\n");
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
