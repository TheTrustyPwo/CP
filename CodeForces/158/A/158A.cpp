#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	int cut = a[k - 1];
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (a[i] >= cut && a[i] > 0) ans++;
	cout << ans;
}
