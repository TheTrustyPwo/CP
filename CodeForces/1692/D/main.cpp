#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    string s; int n; cin >> s >> n;
    stringstream ss(s);
    int h, m, t = 0; char sep;
    ss >> h >> sep >> m;

    unordered_set<int> us;
    while (!t || t % 1440 != 0) {
        m += n;
        h += (m / 60);
        m %= 60;
        h %= 24;
        if (h / 10 == m % 10 && h % 10 == m / 10) {
            us.insert(h * 100 + m);
        }
        t += n;
    }
    cout << us.size() << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
