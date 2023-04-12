#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
        int e; cin >> e;
        if (e == 0) cnt0++;
        else cnt1++;
    }
    if (cnt0 >= n / 2) {
        cout << cnt0 << '\n';
        for (int i = 0; i < cnt0; i++) cout << 0 << ' ';
        cout << '\n';
    } else {
        if (cnt1 & 1) {
            cout << cnt1 - 1 << '\n';
            for (int i = 1; i < cnt1; i++) cout << 1 << ' ';
            cout << '\n';
        } else {
            cout << cnt1 << '\n';
            for (int i = 0; i < cnt1; i++) cout << 1 << ' ';
            cout << '\n';
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
