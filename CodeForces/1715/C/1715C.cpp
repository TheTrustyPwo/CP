#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	
	int a[n + 2]; a[0] = a[n + 1] = 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] != a[i + 1]) ans += (n - i) * i;
	
	while (m--) {
		int i, x; cin >> i >> x;
		ans -= (a[i] != a[i - 1]) * (n - i + 1) * (i - 1);
		ans -= (a[i] != a[i + 1]) * (n - i) * i;
		a[i]= x;
		ans += (a[i] != a[i - 1]) * (n - i + 1) * (i - 1);
		ans += (a[i] != a[i + 1]) * (n - i) * i;
		cout << ans + n * (n + 1) / 2 << '\n';
	}
}
