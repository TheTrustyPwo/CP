#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n; string s; cin >> s;
    int w = 0;
    for (int i = 0; i < (n / 2); i++) if (s[i] != s[n - i - 1]) w++;
    int g = (n / 2) - w;
    for (int i = 0; i <= n; i++) {
        if (i < w) { cout << 0; continue; }
        if ((i - w) & 1) {
            if ((n & 1) && g >= -1) { cout << 1; g = (g == -1 ? -2 : g); }
            else cout << 0;
        } else {
            if (g >= 0) {
                cout << 1;
                g--;
            } else cout << 0;
        }
    } cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
