#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	
	double lower = 0, upper = 1e18;
	for (int i = 0; i < n - 1; i++) {
		double m = ((double) b[i + 1] - b[i]) / ((double) a[i + 1] - a[i]);
		if (a[i + 1] - a[i] > 0) lower = max(lower, m);
		else upper = min(upper, m);
	}
	
	if (lower > upper || upper < 0) cout << "NO\n";
	else cout << "YES\n";
}
