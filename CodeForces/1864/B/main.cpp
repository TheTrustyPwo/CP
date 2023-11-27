#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    if (k & 1) {
        vector<char> v1, v2;
        for (int i = 0; i < n; i++) {
            if (i & 1) v2.push_back(s[i]);
            else v1.push_back(s[i]);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        string ans = "";
        for (int i = 0, j = 0; i < v1.size() || j < v2.size(); i++, j++) {
            if (i < v1.size()) ans += v1[i];
            if (j < v2.size()) ans += v2[i];
        }
        cout << ans << '\n';
    } else {
        sort(s.begin(), s.end());
        cout << s << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
