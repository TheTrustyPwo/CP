#include <bits/stdc++.h>
using namespace std;
#define int long long
const int m = 998244353;

int p[2000005], temp[2000005];
map<int, int> a, b;

void test_case(int test) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> temp[i];
    for (int i = 0; i < n; i++) { int x; cin >> x; a[temp[i]] = x; }
    int m; cin >> m;
    for (int i = 0; i < m; i++) cin >> temp[i];
    for (int i = 0; i < m; i++) { int x; cin >> x; b[temp[i]] = x; }

    int ans = 0;
    for (const pair<int, int> &p : b) {
        a[p.first] -= p.second;
        if (a[p.first] < 0) { cout << 0; return; }
    }

    for (const pair<int, int> &p : a) if (p.second > 0) ans++;

    cout << p[ans];
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    p[0] = 1; for (int i = 1; i <= 2000000; i++) p[i] = (p[i - 1] * 2) % m;
    for (int i = 1; i <= 1; i++) test_case(i);
    return 0;
}
