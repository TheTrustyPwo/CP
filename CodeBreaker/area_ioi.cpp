#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int ans = 0;
	while (n--) {
		int h, w; cin >> h >> w;
		ans = max(ans, h * w);
	}
	cout << ans;
}
