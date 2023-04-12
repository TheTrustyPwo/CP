#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int first, mn = 1e9; cin >> first;
    for (int i = 1; i < n; i++) { int x; cin >> x; mn = min(mn, x); }
    cout << (first > mn ? "Alice\n" : "Bob\n");
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
