#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    string s; cin >> s;
    int hori = 0, vert = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            cout << 1 << ' ' << hori * 2 + 1 << '\n';
            hori ^= 1;
        } else if (s[i] == '0') {
            cout << 2 << ' ' << vert + 1 << '\n';
            vert = (vert + 1) % 4;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test_case(1);
    return 0;
}
