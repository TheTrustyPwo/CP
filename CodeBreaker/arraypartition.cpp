#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, s, l; cin >> n >> s >> l;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	int cur = a[0], cnt = 1, ans = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] == cur) cnt++;
		else {
			if (cnt < l) { cout << -1; return 0; }
			cur = a[i];
			cnt = 1;
			ans++;
		}
	}
	
	cout << ans;
}
