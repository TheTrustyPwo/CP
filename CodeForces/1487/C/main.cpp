#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    if (n & 1) {
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (j - i <= n / 2) cout << 1 << ' ';
                else cout << -1 << ' ';
        cout << '\n';
    } else {
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (j - i < n / 2) cout << 1 << ' ';
                else if (j - i == n / 2) cout << 0 << ' ';
                else cout << -1 << ' ';
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
