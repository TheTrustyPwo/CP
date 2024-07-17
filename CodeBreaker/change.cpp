#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b, c, d, n, w, x, y, z; cin >> a >> b >> c >> d >> n;
	int m = n;
	w = min(d, n / 50);
	n -= w * 50;
	x = min(c, n / 20);
	n -= x * 20;
	y = min(b, n / 10);
	n -= y * 10;
	z = min(a, n / 5);
	n -= z * 5;
	if (n != 0) {
		n = m;
		w = max(0, min(d, n / 50) - 1);
		n -= w * 50;
		x = min(c, n / 20);
		n -= x * 20;
		y = min(b, n / 10);
		n -= y * 10;
		z = min(a, n / 5);
		n -= z * 5;
		if (n != 0) {
			cout << -1;
			return 0;
		}
	}
	cout << z << ' ' << y << ' ' << x << ' ' << w << ' ' << w + x + y + z;
}
