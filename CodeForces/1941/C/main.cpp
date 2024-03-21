#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; string s; cin >> n >> s;

    int ans = 0;
    for (int i = n - 1; i >= 2; i--) {
        if (s[i] == 'e' && s[i - 1] == 'i' && s[i - 2] == 'p') {
            if (i > 2 && s[i - 3] != 'p') {
                ans++;
                i -= 2;
            } else {
                ans++;
                i -= 1;
            }
        } else if (s[i] == 'p' && s[i - 1] == 'a' && s[i - 2] == 'm') {
            ans++;
            i -= 1;
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
