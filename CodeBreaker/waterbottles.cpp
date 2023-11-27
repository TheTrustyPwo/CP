#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int h, w, k; cin >> h >> w >> k;
	
	ll sum = 0;
	for (int i = 0; i < h * w; i++) {
		int x; cin >> x;
		sum += x;
	}
	
	ll ans = sum - (2 * h * w - h - w) * k;
	cout << ans;
}
