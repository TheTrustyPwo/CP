#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	double m, n; cin >> m >> n;
	double ans = m;
	for (int i = 1; i < m; i++)
		ans -= pow(i / m, n);
	cout << ans;
}
