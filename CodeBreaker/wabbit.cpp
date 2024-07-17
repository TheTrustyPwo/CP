#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, q, k, a[300005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q >> k; k++;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, greater<int>());
	for (int i = 1; i < n; i++) a[i] += a[i - 1];
	while (q--) {
		int x; cin >> x;
		int dbl = x / k;
		cout << a[x - 1] + a[dbl - 1] << '\n';
	}
}
