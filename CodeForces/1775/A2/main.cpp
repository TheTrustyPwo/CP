#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    string s; cin >> s;
    if (s[0] == 'a') {
        if (s[1] == 'a') {
            cout << "a a " << s.substr(2, s.size() - 2) << '\n';
        } else {
            cout << "a " << s.substr(1, s.size() - 2) << ' ' << s[s.size() - 1] << '\n';
        }
    } else {
        if (s[1] == 'b') {
            cout << "b b " << s.substr(2, s.size() - 2) << '\n';
        } else {
            int nxb = -1;
            for (int i = 1; i < s.size(); i++)
                if (s[i] == 'b') { nxb = i; break; }
            if (nxb != -1) {
                cout << "b " << s.substr(1, nxb - 1) << ' ' << s.substr(nxb, s.size() - nxb) << '\n';
            } else {
                cout << "b a " << s.substr(2, s.size() - 2) << '\n';
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
