#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;
        if (b[i] < a[i]) { cout << "NO\n"; return; }
        bool bl = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > b[i]) break;
            if (b[j] < b[i]) break;
            if (a[j] == b[i]) bl |= 1;
        }
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] > b[i]) break;
            if (b[j] < b[i]) break;
            if (a[j] == b[i]) bl |= 1;
        }
        if (!bl) { cout << "NO\n"; return; }
    }
    cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
