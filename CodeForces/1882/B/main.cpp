#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    bitset<55> a[n]; set<int> s;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            a[i].set(x);
            s.insert(x);
        }
    }

    int mx = 0;
    for (const int u : s) {
        bitset<55> b;
        for (int i = 0; i < n; i++) if (!a[i].test(u)) b |= a[i];
        mx = max(mx, (int) b.count());
    }

    cout << mx << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
