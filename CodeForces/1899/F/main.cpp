#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, q; cin >> n >> q;
    int a[q]; for (int i = 0; i < q; i++) cin >> a[i];

    for (int i = 0; i < n - 1; i++) cout << i + 1 << ' ' << i + 2 << '\n';

    int cur = n - 1;
    for (int i = 0; i < q; i++) {
        int req = a[i];
        if (req == cur) cout << "-1 -1 -1\n";
        else {
            cout << n << ' ' << cur << ' ' << req << '\n';
            cur = req;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
