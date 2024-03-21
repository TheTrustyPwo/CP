#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int conv(char ch) {
    if (ch == 'S') return 0;
    else if (ch == 'D') return 1;
    else if (ch == 'C') return 2;
    return 3;
}

void test_case(int test) {
    int n; cin >> n; char ch; cin >> ch;
    int a[2 * n];
    int cnt[4]{};
    vector<string> dat[4];
    for (int i = 0; i < 2 * n; i++) {
        string s; cin >> s; int suit = conv(s[1]);
        dat[suit].push_back(s);
        cnt[suit]++;
    }
    
    int req = 0;
    for (int i = 0; i < 4; i++) {
        sort(dat[i].begin(), dat[i].end());
        if (i == conv(ch)) continue;
        req += cnt[i] & 1;
    }

    if (req > cnt[conv(ch)]) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<string> extra;
    for (int i = 0; i < 4; i++) {
        if (i == conv(ch)) continue;
        for (int j = 1; j < dat[i].size(); j += 2)
            cout << dat[i][j - 1] << ' ' << dat[i][j] << '\n';
        if (dat[i].size() & 1) extra.push_back(dat[i].back());
    }

    int king = conv(ch);
    for (int i = 0; i < extra.size(); i++) {
        cout << extra[i] << ' ' << dat[king][i] << '\n';
    }
    for (int i = extra.size() + 1; i < dat[king].size(); i += 2) {
        cout << dat[king][i - 1] << ' ' << dat[king][i] << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
