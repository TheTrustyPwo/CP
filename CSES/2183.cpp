#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] - cur >= 2) {
			cout << cur + 1;
			return 0;
		}
		cur += a[i];
	}
	cout << cur + 1;
}
