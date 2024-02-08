#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n; string s; cin >> s;
    int first = -1, last = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            last = i;
            if (first == -1) first = i;
        }
    }
    if (first == -1) cout << 0 << '\n';
    else cout << last - first + 1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
