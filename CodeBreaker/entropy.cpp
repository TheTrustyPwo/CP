#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	
	if (n == 1 || k == n) { cout << 0; return 0; }
	
	int mx = 0;
	for (int i = 0; i <= k; i++)
		mx = max(mx, a[n - 1] - a[n - i - 1] + a[k - i] - a[0]);
	
	cout << a[n - 1] - a[0] - mx;
}
