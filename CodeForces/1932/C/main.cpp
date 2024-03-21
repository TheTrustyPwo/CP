#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, t[524288];

void update(int p, int v) {
    for (t[p += n] = v; p > 1; p >>= 1) t[p >> 1] = (t[p] * t[p ^ 1]) % m;
}
    
int query(int l, int r) {
    int res = 1;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = (res * t[l++]) % m;
        if (r & 1) res = (res * t[--r]) % m;
    }
    return res;
}

void test_case(int test) {
    cin >> n >> m;
    int l = 0, r = n - 1;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        update(i, x);
    }

    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        cout << query(l, r) << ' ';
        if (s[i] == 'L') l++;
        else r--;
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
