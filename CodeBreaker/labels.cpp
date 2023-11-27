#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n]; for (int i = 1; i < n; i++) cin >> a[i];
	int ans[n]; ans[0] = 1;
	for (int i = 1; i < n; i++) ans[i] = a[i] + ans[i - 1];
	
	int mn = *min_element(ans, ans + n);
	for (int i = 0; i < n; i++) ans[i] += (1 - mn);
	
	if (find(ans, ans + n, 1) != (ans + n) && find(ans, ans + n, n) != (ans + n)) {
		for (int i = 0; i < n; i++) cout << ans[i] << ' ';
	} else cout << -1;
}
