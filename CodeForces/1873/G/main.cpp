#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    string s; cin >> s; int n = s.size();
    vector<int> v;
    int cur = 0, cnt = 0, t = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            t = min(t + 1, 2);
            if (cur > 0) {
                v.push_back(cur);
                cur = 0;
            }
        } else cur++, cnt += t, t = 0;
    }

    if (cur > 0) v.push_back(cur);
    cnt += t;

    int sum = accumulate(v.begin(), v.end(), 0);
    if (cnt >= v.size()) {
        cout << sum << '\n';
    } else cout << sum - *min_element(v.begin(), v.end()) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
