#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int ans = 0, prev = -1;
		for (int i = 0; i < (int) s.size(); i++)
			if (s[i] == 'R') ans = max(ans, i - prev), prev = i;
		ans = max(ans, (int) s.size() - prev);
		cout << ans << '\n';
	}
}
