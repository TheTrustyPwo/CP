#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	double t, n, x, k; cin >> t >> n >> x >> k;
	double ans = (double) t;
	for (int i = 0; i < n; i++) {
		double d, s, w; cin >> d >> s >> w;
		ans -= w;
		ans -= (d / s);
	}
	
	ans -= (x / k);
	cout << static_cast<long long>(round(ans));
}
