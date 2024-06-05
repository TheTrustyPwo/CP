#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    int cnt = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum <= a[i]) cnt++, sum += a[i];
    }

    cout << cnt;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
