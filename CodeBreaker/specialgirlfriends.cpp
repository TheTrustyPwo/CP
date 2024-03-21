#include <bits/stdc++.h>
using namespace std;
#define int long long
const int m = 1e9 + 7;

int binpow(int a, int b) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, t; cin >> n >> t; int ans = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		ans = (ans + binpow(x, t)) % m;
	}
	cout << ans;
}
