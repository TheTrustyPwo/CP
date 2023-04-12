#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, ans = 0; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		ans = max(ans, a);
	}
	cout << ans;
}
