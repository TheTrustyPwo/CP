#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    string s; cin >> s;
    stack<int> st;
    for (char ch : s) {
        if (st.empty() || ch == 'A') {
            st.push(ch);
        } else {
            st.pop();
        }
    }
    cout << st.size() << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
