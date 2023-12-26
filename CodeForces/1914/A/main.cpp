#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    map<char, int> mp; string s; cin >> s;
    for (int i = 0; i < n; i++) mp[s[i]]++;
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        char ch = 'A' + i;
        if (mp[ch] >= i + 1) ans++;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
