#include <bits/stdc++.h>
using namespace std;
#define int long long

inline int move(int cur, int amt, int n) {
    if (cur + amt <= n) return cur + amt;
    else return cur - amt;
}

void test_case(int test) {
    int n, k, s; cin >> n >> k >> s;
    int each = ((s + k - 1) / k); int extra = s % each;
    if (k > s || ((s + n - 2) / (n - 1) > k)) { cout << "NO"; return; }
    cout << "YES\n";
    int cur = 1;
    for (int i = (extra != 0); i < k; i++) {
        cur = move(cur, each, n);
        cout << cur << ' ';
    }
    if (extra != 0) cout << move(cur, extra, n);
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test_case(1);
    return 0;
}
