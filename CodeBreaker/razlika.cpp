#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	
	multiset<int> ms; for (int i = 1; i < n - k; i++) ms.insert(a[i] - a[i - 1]);
	int ans = *ms.begin() + a[n - k - 1] - a[0];
	for (int i = 1; i <= k; i++) {
		ms.erase(a[i] - a[i - 1]); ms.insert(a[i + n - k - 1] - a[i + n - k - 2]);
		ans = min(ans, *ms.begin() + a[i + n - k - 1] - a[i]);
	}
	
	cout << ans;
}
