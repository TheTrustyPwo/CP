#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k, ans = 0; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		if (a * b < k) ans++;
	}
	cout << ans;
}
