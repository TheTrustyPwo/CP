#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, k;
string s;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k >> s;
	
	int cnt = 0;
	for (int i = 0; i < n; i++) if (s[i] == 'x') cnt++;
	k = min(k, m * cnt);
	
	int ans = 0;
	if (k >= cnt) {
		int tmp = min(k / cnt, m) - 2;
		if (tmp > 0) {
			ans += tmp * n;
			k -= tmp * cnt;
		}
	}
	
	vector<pair<int, bool>> a;
	bool b = s[0] == 'x'; int c = 1;
	for (int i = 1; i < n; i++) {
		if ((b && s[i] == 'x') || (!b && s[i] == 'o')) c++;
		else {
			a.push_back(make_pair(c, b));
			c = 1, b = s[i] == 'x';
		}
	}
	
	if (c) a.push_back(make_pair(c, b));
	
	int tmp = a.size();
	a.push_back(make_pair(n, 0));
	for (int i = 0; i < tmp; i++) a.push_back(a[i]);
	
	int l = 0, r = 0, cur = 0, req = 0, mx = 0;
	while (r < a.size()) {
		cout << l << ' ' << r << ' ' << cur << ' ' << req << '\n';
		if (a[r].second == 0) cur += a[r].first, r++;
		else {
			if (req + a[r].first > k) {
				mx = max(mx, cur + k - req);
				if (a[l].second == 0) cur -= a[l].first, l++; 
				else cur -= a[l].first, req -= a[l].first, l++;
			} else req += a[r].first, cur += a[r].first, r++;
		}
		mx = max(mx, cur);
	}
	
	ans += mx - n;
	cout << ans;
	
	for (auto p : a) cout << p.first << ' ' << p.second << '\n';
}
