#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int a[3]; cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    cout << (a[1] + a[2] >= 10 ? "YES\n" : "NO\n");
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
