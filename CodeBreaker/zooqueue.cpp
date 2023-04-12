#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	
	int dp[n]; dp[0] = a[0];
	for (int i = 1; i < n; i++) dp[i] = max(dp[i - 1], a[i]);
	
	set<int> s;
	for (int i = n - 1; i; i--) {
		s.insert(a[i]);
		auto it = s.upper_bound(a[i]);
		if (it == s.end()) continue;
		if (dp[i] > *it) {
			cout << "seven years of misfortune";
			return 0;
		}
	}
	
	cout << "safe and sound";
}
