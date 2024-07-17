#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int freq[n + 1]; fill(freq, freq + n + 1, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }

    bool b = 0; int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (freq[i] == 0) { ans = i; break; }
        if (freq[i] == 1) {
            if (b) { ans = i; break; }
            else b = 1;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
