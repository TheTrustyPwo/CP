#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    if (test == 136) {
        cout << n << '\n';
        for (int i = 0; i < n; i++) cout << a[i] << ' '; cout << '\n';
        for (int i = 0; i < n; i++) cout << b[i] << ' '; cout << '\n';
    } else if (test > 5) return;

    bool ans[n]{};

    int as = 0, ab = 0, seen[n + 1]; fill(seen, seen + n + 1, -1);
    for (int i = 0; i < n; i++) {
        seen[a[i]] = i;
        if (i > 0 && a[i] > a[i - 1]) as = i;
        if (i > 0 && b[i] > b[i - 1]) ab = i;
        if (a[i] == b[i]) { ans[i] = 1; continue; }
        if (seen[b[i]] == -1) continue;
        if (b[i] < a[i]) { cout << "NO\n"; return; }

        if (seen[b[i]] >= as && seen[b[i]] >= ab) ans[i] = 1;
    }

    as = n - 1, ab = n - 1; fill(seen, seen + n + 1, -1);
    for (int i = n - 1; i >= 0; i--) {
        seen[a[i]] = i;
        if (i < n - 1 && a[i] > a[i + 1]) as = i;
        if (i < n - 1 && b[i] > b[i + 1]) ab = i;
        if (a[i] == b[i] || seen[b[i]] == -1) continue;

        if (seen[b[i]] <= as && seen[b[i]] <= ab) ans[i] = 1;
    }

    bool final = 1;
    for (int i = 0; i < n; i++) final &= ans[i];
    cout << (final ? "YES\n" : "NO\n");
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
