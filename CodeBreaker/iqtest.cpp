#include <bits/stdc++.h>
using namespace std;
#define int long long

int pow(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int inv(int a, int m) {
  return a <= 1 ? a : m - (m / a) * inv(m % a, m) % m;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, p; cin >> a >> p;
		int ans = (((pow(a, p + 1, p) + p - 1) % p) * inv(a - 1, p)) % p;
		cout << ans << '\n';
	}
}
