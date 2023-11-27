#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n, k; cin >> n >> k; bool b = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == k) b = 1;
    }
    cout << (b ? "YES\n" : "NO\n");
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
