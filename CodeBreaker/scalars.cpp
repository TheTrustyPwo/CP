#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	
	sort(a, a + n);
	sort(b, b + n, greater<int>());
	
	int ans = 0;
	for (int i = 0; i < n; i++) ans += a[i] * b[i];
	cout << ans;
}
