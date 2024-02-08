#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> g[200005];

void test_case(int test) {
    int n; cin >> n;
    for (int i = 0; i <= n; i++) g[i].clear();
    for (int i = 25; i >= 0; i--) g[0].push_back(i);
    string s = "";
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        int v = g[x].back();
        char ch = 'a' + v;
        s += ch;
        g[x].pop_back();
        g[x + 1].push_back(v);
    }
    cout << s << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
