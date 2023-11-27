#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n, k; string s; cin >> n >> k >> s;
    int l[k], r[k];
    for (int i = 0; i < k; i++) { cin >> l[i]; l[i]--; }
    for (int i = 0; i < k; i++) { cin >> r[i]; r[i]--; }
    int q; cin >> q; int cnt[n+1]{};
    while (q--) {
        int x; cin >> x;
        cnt[x-1]++;
    }

    string ans = "";
    for (int i = 0; i < k; i++) {
        string s1 = s.substr(l[i], r[i] - l[i] + 1);
        int sum = 0;
        for (int j = l[i]; j <= (l[i] + r[i]) / 2; j++) {
            sum += cnt[j] + cnt[r[i] - j + l[i]];
            if (sum & 1) swap(s1[j - l[i]], s1[r[i] - j]);
        }
        ans += s1;
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
