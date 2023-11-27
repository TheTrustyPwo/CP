#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n + 1]; for (int i = 0; i <= n; i++) cin >> a[i];
	int b[n]; for (int i = 0; i < n; i++) cin >> b[i];

	sort(a, a + n + 1);
	sort(b, b + n);
	
	int pre1[n]; pre1[0] = max(a[0] - b[0], 0);
	for (int i = 1; i < n; i++) pre1[i] = max(pre1[i - 1], max(a[i] - b[i], 0));
	
	int suf[n]; suf[n - 1] = max(a[n] - b[n - 1], 0);
	for (int i = n - 2; i >= 0; i--) suf[i] = max(suf[i + 1], max(a[i + 1] - b[i], 0));
	
	for (int i = 0; i <= n; i++) {
		if (i == 0) cout << suf[0];
		else if (i == n) cout << pre1[n - 1];
		else cout << max(suf[i], pre1[i - 1]);
		cout << ' ';
	}
}
