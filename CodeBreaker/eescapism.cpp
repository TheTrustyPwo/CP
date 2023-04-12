#include <bits/stdc++.h>
using namespace std;
#define int long long
const int m = 1e9 + 7;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = (ans + ((a[i] * (a[i] + 1)) % m * 500000004) % m) % m;
	cout << ans;
}
