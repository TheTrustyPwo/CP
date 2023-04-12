#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    string s; cin >> s;
    string a, b, c;
    for (int i = 0; i < s.size() - 2; i++) {
        a = s.substr(0, i + 1);
        for (int j = i; j < s.size() - 1; j++) {
            b = s.substr(i + 1, j - i + 1);
            c = s.substr(j + 2, s.size() - j);
            // cout << a << ' ' << b << ' ' << c << '\n';
            if ((b >= a && b >= c) || (b <= a && b <= c)) { cout << a << ' ' << b << ' ' << c << '\n'; return; }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
