#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
    // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    pair<int, int> wins[n];
    for (int i = 0; i < n; i++) {
        string s(n, '1'); s[i] = '0';
        cout << "? " << i + 1 << ' ' << s << '\n';
        cin >> wins[i].first; wins[i].second = i;
    }

    sort(wins, wins + n, greater<pair<int, int>>());

    string ans(n, '0');
    ans[wins[0].second] = '1';
    int stop = 0;

    for (int i = 1; i < n; i++) {
        int idx = wins[i].second;
        cout << "? " << idx + 1 << ' ' << ans << '\n';
        int w; cin >> w; if (!w) continue;
        for (int j = stop; j <= i; j++) ans[wins[j].second] = '1';
        stop = i + 1;
    }

    cout << "! " << ans;

    return 0;
}
