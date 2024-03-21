#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n; int ans = 1e18;
	for (int i = 0; i <= 63; i++) {
		int x = (1LL << i);
		int a = n / x;
		int c = n % x;
		ans = min(a + i + c, ans);
	}
	cout << ans;
}
