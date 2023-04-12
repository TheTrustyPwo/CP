#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n, m; cin >> n;
    int a[n], b[n];
    unordered_map<int, int> mp; stack<int> st; bool bb = true;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    cin >> m;
    for (int i = 0; i < m; i++) { int x; cin >> x; mp[x]++; }
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) { bb = false; break; }
        while (!st.empty() && st.top() < b[i]) st.pop();
        if ((st.empty() || st.top() != b[i]) && a[i] > b[i]) {
            st.push(b[i]);
            if (!mp[b[i]]) { bb = false; break; }
            mp[b[i]]--;
        }
    }
    cout << (bb ? "YES\n" : "NO\n");
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
