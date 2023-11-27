#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int bs = 0;
    for (int i = 0; i < n; i++) if (s[i] == 'B') bs++;

    if (bs == k) {
        cout << 0 << '\n';
        return;
    }

    if (bs < k) {
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'B') cnt++;
            if (cnt + i + 1 == k) {
                cout << 1 << '\n';
                cout << i + 1 << ' ' << 'B' << '\n';
                return;
            }
        }
    } else {
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'A') cnt++;
            if (cnt + i + 1 == n - k) {
                cout << 1 << '\n';
                cout << i + 1 << ' ' << 'A' << '\n';
                return;
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
