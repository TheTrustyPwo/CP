#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b, c; cin >> a >> b >> c;
    cout << max({a + b + c, (a + b) * c, a * (b + c), a * b * c});
    return 0;
}
