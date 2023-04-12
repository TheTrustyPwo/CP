#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int a[n], p[n], q[n]; vector<int> x, y, b[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]].push_back(i);
    }

    for (int i = n; i; i--) {
        if (b[i].size() > 2) {
            cout << "NO\n";
            return;
        } else if (b[i].size() == 2) {
            p[b[i][0]] = q[b[i][1]] = i;
            x.push_back(b[i][1]), y.push_back(b[i][0]);
        } else if (b[i].size() == 1) {
            p[b[i][0]] = q[b[i][0]] = i;
        } else {
            if (x.empty()) { cout << "NO\n"; return; }
            p[x.back()] = q[y.back()] = i;
            x.pop_back(); y.pop_back();
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << p[i] << ' '; cout << '\n';
    for (int i = 0; i < n; i++) cout << q[i] << ' '; cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
