#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			string s; cin >> s;
			if (s == "pavement") ans1 = i, ans2 = j;
		}
	}
	cout << ans1 << ' ' << ans2;
}
