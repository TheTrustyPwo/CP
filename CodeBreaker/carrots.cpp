#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	
	int l = 1, r = *max_element(a, a + n), ans;
	while (l <= r) {
		int m = l + (r - l) / 2;
		
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += (a[i] / m + (a[i] % m != 0));
		}
		
		if (cnt <= k) {
			ans = m;
			r = m - 1;
		} else l = m + 1;
	}
	
	int total = 0, cnt = 0;
	map<int, int, greater<int>> mp;
	for (int i = 0; i < n; i++) {
		if (a[i] <= ans) {
			total += a[i] * a[i];
			mp[a[i]]++;
		} else {
			total += ((a[i] / ans - 1) * ans * ans);
			mp[ans] += (a[i] / ans - 1);
			if (a[i] % ans == 0) {
				total += ans * ans;
				mp[ans]++;
			} else {
				int f = (ans + (a[i] % ans)) / 2;
				int c = ans + (a[i] % ans) - f;
				total += (f * f + c * c);
				mp[f]++;
				mp[c]++;
			}
		}
		cnt += (a[i] / ans + (a[i] % ans != 0));
	}
	
	int diff = k - cnt;
	for (const auto &p : mp) {
		int replace = min(p.first, diff);
		
	}
	
	cout << total;
}
