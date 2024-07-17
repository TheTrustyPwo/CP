#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, c; cin >> n >> c;
	int a[n], b[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	
	sort(a, a + n);
	sort(b, b + n);
	
	int ans = 0;
	for (int i = 0; i < n; i += c) {
		ans += abs(a[i] - b[n - i - 1]);
	}
	cout << ans << '\n';
	for (int i = 0; i < n; i += c) {
		for (int j = i; j < min(n, i + c); j++) cout << a[j] << ' ';
		for (int j = max((int) 0, n - i - c); j < n - i; j++) cout << b[j] << ' ';
	}
}
