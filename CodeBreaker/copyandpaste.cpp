#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	int b[n]; for (int i = 0; i < n; i++) cin >> b[i];
	int l, r; cin >> l >> r; l--; r--;
	int sa = 0, sb = 0;
	for (int i = l; i <= r; i++) sa += a[i];
	for (int i = l; i <= r; i++) sb += b[i];
	if (sa != sb) { cout << "NO"; return 0; }
	
	for (int i = 0; i < l; i++)
		if (a[i] != b[i]) { cout << "NO"; return 0; }
		
	for (int i = r + 1; i < n; i++) {
		if (a[i] != b[i]) { cout << "NO"; return 0; }
	}
	
	cout << "YES";
}
