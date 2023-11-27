#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    char ch[8][8];
    for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) cin >> ch[i][j];
    int k = -1; string ans = "";
    for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) {
        if (k == -1 && ch[i][j] != '.') k = j;
        if (k == j && ch[i][j] != '.') ans += ch[i][j];
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
