#include <bits/stdc++.h>
using namespace std;
#define int long long

int valid(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return i;
    } return 0;
}

void test_case(int test) {
    int a, b; cin >> a >> b;
    if (b <= 3) { cout << -1 << '\n'; return; }
    for (int i = a; i <= b; i++) {
        int res = valid(i);
        if (!res) continue;
        cout << i / res << ' ' << i - (i / res) << '\n';
        return;
    }
    cout << -1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
