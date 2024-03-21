#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int a, b, xk, yk, xq, yq; cin >> a >> b >> xk >> yk >> xq >> yq;
    int dir[8][2] = {{a, b}, {-a, b}, {a, -b}, {-a, -b}, {b, a}, {-b, a}, {b, -a}, {-b, -a}};
    set<pair<int, int>> s1, s2;
    for (int i = 0; i < 8; i++) s1.insert(make_pair(xk + dir[i][0], yk + dir[i][1]));
    for (int i = 0; i < 8; i++) s2.insert(make_pair(xq + dir[i][0], yq + dir[i][1]));
    set<pair<int, int>> ans;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(ans, ans.begin()));
    cout << ans.size() << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
