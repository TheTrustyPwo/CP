#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, k; cin >> n >> k;
    if ((k & 1) || (k > 0 && k < n)) { cout << "No\n"; return; }
    if (k == 0) {
        cout << "Yes\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << 0 << ' ';
            } cout << '\n';
        } return;
    } else if (k == n * n) {
        cout << "Yes\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << 1 << ' ';
            } cout << '\n';
        } return;
    } else if ((ceil((double)sqrt(k)) == floor((double)sqrt(k))) && ((int)floor((double)sqrt(k)) % 2 == 0)) {
        int r = floor((double)sqrt(k));
        cout << "Yes\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i <= r && j <= r) cout << 1 << ' ';
                else cout << 0 << ' ';
            } cout << '\n';
        } return;
    }


    int v = n * n - k;
    int a = 0, b = 0; bool ok = false;

    for (int x = 1; x <= min(n, v); x++) {
        if (v % x == 0 && (v / x) <= n) {
            ok = true;
            a = x, b = v / x;
            break;
        }
    }

    if (!ok) {
        for (int x = 0; x <= n; x++) {
            int top = v - n * x;
            int bottom = n - 2 * x;
            if (bottom > 0 && top >= 0 && (top % bottom == 0) && (top / bottom <= n)) {
                a = x, b = top / bottom;
                ok = true;
                break;
            }
        }
        if (!ok) { cout << "No\n"; return; }
        cout << "Yes\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if ((i <= a && j <= b) || (i > a && j > b)) cout << 1 << ' ';
                else cout << 0 << ' ';
            } cout << '\n';
        }
        return;
    }

    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i <= a && j <= b) cout << 0 << ' ';
            else cout << 1 << ' ';
        } cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
