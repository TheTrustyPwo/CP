#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; string s; cin >> n >> s;

    bool sorted = 1;
    for (int i = 1; i < n; i++) if (s[i] < s[i - 1]) sorted = false;
    if (sorted) {
        cout << 0 << '\n';
        return;
    }

    vector<char> c; vector<int> idx;
    for (int i = 0; i < n; i++) {
        while (!c.empty() && s[i] > c.back()) {
            c.pop_back();
            idx.pop_back();
        }
        c.push_back(s[i]);
        idx.push_back(i);
    }

    int cnt = 0;
    for (int i = 0; i < c.size(); i++)
        if (c[i] == c[0]) cnt++;
        else break;

    reverse(c.begin(), c.end());

    for (int i = 0; i < c.size(); i++) {
        s[idx[i]] = c[i];
    }

    for (int i = 1; i < n; i++) {
        if (s[i] < s[i - 1]) {
            cout << -1 << '\n';
            return;
        }
    }

    cout << c.size() - cnt << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
