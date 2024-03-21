#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (x == i || x == n) ans++;
	}
	cout << ans;
}
