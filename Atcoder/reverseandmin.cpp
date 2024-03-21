#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n; string s; cin >> s;
	string r = s; reverse(r.begin(), r.end());
	int k1 = atoll(s.c_str()), k2 = atoll(r.c_str());
	int ans = 0;
	if (k2 < k1) { cout << 0; return 0; }
	if (k1 == k2) k2 = n + 1;
	while (k1 <= n || k2 <= n) {
		if (k1 <= n) ans++, k1 *= 10;
		if (k2 <= n) ans++, k2 *= 10;
	}
	cout << ans;
}
