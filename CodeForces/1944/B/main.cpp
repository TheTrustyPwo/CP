#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n, k; cin >> n >> k; k *= 2;
    int a[2 * n], occ[n + 1]; fill(occ, occ + n + 1, 0);
    for (int i = 0; i < 2 * n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) occ[a[i]]++;

    vector<int> g0, g1, g2;
    for (int i = 1; i <= n; i++) {
        if (occ[i] == 0) g0.push_back(i);
        else if (occ[i] == 1) g1.push_back(i);
        else g2.push_back(i);
    }

    int cnt = 0;
    for (const int v : g2) {
        if (cnt >= k) break;
        cout << v << ' ' << v << ' ';
        cnt += 2;
    }
    for (const int v : g1) {
        if (cnt >= k) break;
        cout << v << ' ';
        cnt += 1;
    }
    cout << '\n';

    cnt = 0;
    for (const int v : g0) {
        if (cnt >= k) break;
        cout << v << ' ' << v << ' ';
        cnt += 2;
    }
    for (const int v : g1) {
        if (cnt >= k) break;
        cout << v << ' ';
        cnt += 1;
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
