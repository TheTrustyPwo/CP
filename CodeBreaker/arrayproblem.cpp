#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	int suffix[n];
	suffix[n-1] = a[n-1];
	for (int i = n - 2; i >= 0; i--) suffix[i] = suffix[i+1] + a[i];
	int ans = suffix[0];
	sort(suffix + 1, suffix + n, greater<int>());
	for (int i = 1; i < k; i++) ans += suffix[i];
	cout << ans;
}
