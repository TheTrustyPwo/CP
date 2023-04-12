#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n, a, b, l = 0, r = 0; cin >> n;
	map<ll, pair<bool, int>> m;
	while (n--) {
		cin >> a;
		if (a == 1) {
			cin >> b;
			m[b] = make_pair(0, l);
			l++;
		} else if (a == 2) {
			cin >> b;
			m[b] = make_pair(1, r);
			r++;
		} else if (a == 3) l--;
		else if (a == 4) r--;
		else if (a == 5) {
			cin >> b;
			if (m[b].first) cout << l + m[b].second + 1 << endl;
			else cout << l - m[b].second << endl;
		} else {
			cin >> b;
			if (m[b].first) cout << r - m[b].second << endl;
			else cout << r + m[b].second + 1 << endl;
		}
	}
}
