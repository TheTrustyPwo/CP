#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    string s; cin >> s;
    multiset<pair<char, int>> m; m.insert(make_pair(s[0], 0));
    for (int i = 1; i < (int) s.size(); i++) {
        while (!m.empty() && m.rbegin() -> first > s[i]) m.erase(*m.rbegin());
        m.insert(make_pair(s[i], i));
    }

    multiset<char> ans;
    for (const auto x : m) ans.insert(x.first);
    for (int i = 0; i < (int) s.size(); i++) {
        if (m.find(make_pair(s[i], i)) != m.end()) continue;
        ans.insert(min(++s[i], '9'));
    }

    for (const auto x : ans) cout << x;
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
