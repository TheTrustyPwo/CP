#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; string s; cin >> n >> m >> s;
	int mx = 0, cur = 0, left = m;
	for (int i = 0; i < n; i++) {
		if (s[i] == '2') cur++;
		else if (s[i] == '1') {
			if (left == 0) cur++;
			else left--;
		}
		if (s[i] == '0' || i == n - 1) {
			mx = max(mx, cur);
			cur = 0;
			left = m;
		}
	}
	cout << mx;
}
