#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, s; cin >> n >> m >> s;
	int a[m]; for (int i = 0; i < m; i++) cin >> a[i];
	int b[s]; for (int i = 0; i < s; i++) cin >> b[i];
	
	sort(a, a + m);
	sort(b, b + s);
	
	int ans = 0;
	for (int i = 0; i < n; i++) ans = max(ans, a[i] + b[n - i - 1]);
	
	cout << ans;
}
