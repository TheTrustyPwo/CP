#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		a %= 10;
		int res = 1;
		while (b) {
			if (b & 1) res = res * a % 10;
			a = a * a % 10;
			b >>= 1;
		}
		cout << res % 10 << '\n';
	}
}
