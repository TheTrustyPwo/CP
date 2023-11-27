#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, k; cin >> n >> k; k %= (n + 1);
    int a[n], sum = 0; for (int i = 0; i < n; i++) { cin >> a[i]; sum += a[i]; }
    int c = (n * (n + 1)) / 2 - sum;

    vector<int> v;
    for (int i = k; i > 1; i--) v.push_back(a[n - i + 1]);
    if (k > 0) v.push_back(c);
    for (int i = 0; i < n - k; i++) v.push_back(a[i]);
    for (const int u : v) cout << u << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
