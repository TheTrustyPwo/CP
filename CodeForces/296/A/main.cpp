#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    if (n == 1) { cout << "YES\n"; return; }
    int a[1024]{}, mx = 0; for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]++;
        mx = max(mx, a[x]);
    }

    cout << (mx <= (n + 1) / 2 ? "YES\n" : "NO\n");
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= 1; i++) test_case(i);
    return 0;
}
