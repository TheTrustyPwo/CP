#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, x, y; cin >> n >> x >> y;
	int ans = 0, a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		ans += min(a * x, y);
	}
	cout << ans;
}
