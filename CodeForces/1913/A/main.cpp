#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    string s; cin >> s;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i + 1] == '0') continue;
        string f = s.substr(0, i + 1), q = s.substr(i + 1, s.size() - i - 1);
        int a = stoi(f), b = stoi(q);
        if (a >= b) continue;
        else {cout << a << ' ' << b << '\n';return;}
    }
    cout << -1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
