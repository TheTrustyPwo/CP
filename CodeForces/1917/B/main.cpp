#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n; string s; cin >> s;
    set<char> st;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        st.insert(s[i]);
        ans += st.size();
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
