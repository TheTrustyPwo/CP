#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; string s; cin >> n >> s;
    int l; cin >> l;
    unordered_set<char> sp;
    for (int i = 0; i < l; i++) {
        char ch; cin >> ch;
        sp.insert(ch);
    }

    int ans = 0, last = 0;
    for (int i = 0; i < n; i++) {
        if (sp.find(s[i]) == sp.end()) continue;
        ans = max(ans, i - last);
        last = i;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
