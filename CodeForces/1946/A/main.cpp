#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int tmp = (n + 1) / 2 - 1;
    int median = a[tmp];
    int cnt = 0;
    for (int i = tmp; i < n; i++) if (a[i] == median)
    cnt++;
    cout << cnt << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
