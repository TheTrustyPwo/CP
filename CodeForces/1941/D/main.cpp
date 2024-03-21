#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n, m, x; cin >> n >> m >> x;
    vector<int> cnt1(n, 0), cnt2(n, 0); cnt1[x - 1] = 1;
    for (int i = 0; i < m; i++) {
        int r; char ch; cin >> r >> ch;
        for (int j = 0; j < n; j++) {
            if (cnt1[j] == 0) continue;
            // cnt2[j] = cnt1[j] - 1;
            if (ch == '0' || ch == '?') {
                cnt2[(j + r) % n] = cnt1[j] + 1; 
            }
            if (ch == '1' || ch == '?')
                cnt2[(j - r + n) % n] = cnt1[j] + 1; 
        }
        swap(cnt1, cnt2);
        for (int i = 0; i < n; i++) cnt2[i] = 0;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) if (cnt1[i] > 0) cnt++;
    cout << cnt << '\n';
    for (int i = 0; i < n; i++) if (cnt1[i] > 0) cout << i + 1 << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
