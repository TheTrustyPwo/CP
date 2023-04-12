#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n, k = 0, ans = 0; cin >> n;
		for (int i = 0; i < n; i++) {
			char ch; cin >> ch;
			if (ch == '(') k--;
			else k++;
			ans = max(ans, k);
		}
		cout << ans << '\n';
	}
}
