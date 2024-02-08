#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	
	int ans = 0;
	for (int i = 0; i < k; i++) {
		vector<int> v;
		for (int j = i; j < n; j += k) {
			v.push_back(abs(a[j]));
		}
		sort(v.begin(), v.end());
		int median;
		if (v.size() == 1) median = v[0];
		else if (v.size() & 1) median = v[v.size() / 2];
		else median = (v[v.size() / 2] + v[(v.size() / 2) - 1]) / 2;
		for (const int u : v) ans += abs(u - median);
	}
	
	cout << ans;
}
