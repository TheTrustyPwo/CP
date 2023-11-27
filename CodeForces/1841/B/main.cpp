#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int cnt = 0;
    vector<int> v;
    while (n--) {
        int u; cin >> u;
        int x = cnt + (!v.empty() && v.back() > u);
        if (x == 0 || (x == 1 && u <= v[0])) {
            v.push_back(u);
            cnt = x;
            cout << 1;
        } else cout << 0;
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
