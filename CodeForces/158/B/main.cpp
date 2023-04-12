#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; vector<int> a(5, 0); cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]++;
    }

    a[1] = max(a[1] - a[3], 0);
    cout << a[3] + a[4] + (a[1] + 2 * a[2] + 3) / 4;

    return 0;
}
