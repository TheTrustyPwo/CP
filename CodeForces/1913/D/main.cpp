#include <bits/stdc++.h>
using namespace std;
const int m = 998244353;

int n, a[300005];
pair<int, int> t[1048576];

void build(int idx, int l, int r) {
    if (l == r) { t[idx] = make_pair(a[l], l); return; }
    int m = (l + r) / 2;
    build(idx * 2, l, m);
    build(idx * 2 + 1, m + 1, r);
    t[idx] = min(t[idx * 2], t[idx * 2 + 1]);
}

// void update(int idx, int l, int r, int p, int v) {
//     if (l == r) { t[idx].first = v; }
//     int m = (l + r) / 2;
//     if (p <= m) update(idx * 2, l, m, p, v);
//     else update(idx * 2 + 1, m + 1, r, p, v);
//     t[idx] = min(t[idx * 2], t[idx * 2 + 1]);
// }

pair<int, int> query(int idx, int l, int r, int a, int b) {
    if (a > b) return make_pair(1e9, -1);
    if (a == l && r == b) return t[idx];
    int m = (l + r) / 2;
    return min(query(idx * 2, l, m, a, min(b, m)), query(idx * 2 + 1, m + 1, r, max(a, m + 1), b));
}

int dnc(int l, int r) {
    if (l == r) return {1, l};
    if (r - l == 1) return {2, a[l] < a[r] ? l : r};
    pair<int, int> res = query(1, 1, n, l, r);

    pair<int, int> r1 = dnc(l, res.second - 1), r2 = dnc(res.second + 1, r);
    r2.first += (r - r2.second + 1); r2.first %= m;
    r1.first += (r1.second - l + 1); r1.first %= m;
    return {(r1.first * r2.first) % m, res.second};
}

void test_case(int test) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    cout << dnc(1, n).first << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
