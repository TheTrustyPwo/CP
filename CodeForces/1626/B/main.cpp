#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    string s;
    cin >> s;
    vector<int> x(s.length());
    for (int i = 0; i < s.length(); i++) {
        x[i] = s[i] - '0';
    }
    int n = x.size();
    for (int i = n - 2; i >= 0; i--) {
        if (x[i] + x[i + 1] >= 10) {
            x[i + 1] += x[i] - 10;
            x[i] = 1;
            break;
        }
    }
    if (x[0] >= 10) {
        x.push_back(0);
        for (int i = x.size() - 1; i > 0; i--) {
            x[i] = x[i - 1];
        }
        x[0] = 1;
        x[1] -= 10;
    }
    for (int i = 0; i < x.size(); i++) {
        cout << x[i];
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
