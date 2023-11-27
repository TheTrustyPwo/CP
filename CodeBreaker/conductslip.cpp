#include <bits/stdc++.h>
using namespace std;
#define int long long

int c, l, k, s[500005];
pair<int, int> d[500005];
vector<int> a, b;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> c >> l >> k;
	for (int i = 0; i < l; i++) cin >> d[i].second;
	for (int i = 0; i < l; i++) cin >> d[i].first;
	
	for (int i = 0; i <= c; i++) cin >> s[i];
	
	for (int i = 0; i < l; i++) {
		if (d[i].second >= k) a.push_back(d[i].first);
		else b.push_back(d[i].first);
	}
	
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());
	
	for (int i = 1; i < a.size(); i++) a[i] += a[i - 1];
	for (int i = 1; i < b.size(); i++) b[i] += b[i - 1];
	
	int ans = 0;
	
	if (k == 1) {
		cout << a[c - 1];
		return 0;
	}
	
	for (int i = 0; i <= c; i++) {
		int cb = i, ca = c - i;
		if (cb > b.size() || ca > a.size()) continue;
		ans = max(ans, a[ca - 1] + b[cb - 1] - s[i]);
	}
	
	cout << ans;
}
