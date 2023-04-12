#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll h, w; cin >> h >> w;
	ll empty = 0;
	bool g[h][w];
	for (ll i = 0; i < h; i++) {
		for (ll j = 0; j < w; j++) {
			char ch; cin >> ch;
			g[i][j] = ch == '.';
			empty += g[i][j];
		}
	}
	
	ll ans = 0, cnt = 0;
	for (ll i = 0; i < h; i++) {
		for (ll j = 0; j < w; j++)
			if (!g[i][j]) { ans += (cnt * cnt); cnt = 0; }
			else cnt++;
		ans += cnt * cnt;
		cnt = 0;
	}
	
	for (ll i = 0; i < w; i++) {
		for (ll j = 0; j < h; j++)
			if (!g[j][i]) { ans += (cnt * cnt); cnt = 0; }
			else cnt++;
		ans += (cnt * cnt);
		cnt = 0;
	}
	
	cout << ans - empty;
}
