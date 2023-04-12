#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return (static_cast<double>(a.first)/a.second) > (static_cast<double>(b.first)/b.second);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	pair<int, int> a[n];
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	sort(a, a + n, &cmp);
	// for (int i = 0; i < n; i++) cout << a[i].first << ' ' << a[i].second << endl;
	int cost = 0;
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (k <= 0) break;
		if (k - a[i].first < 0) continue;
		int x = k / a[i].first;
		for (int i = 0; i < x; i++) ans.push_back(a[i].first);
		cost += a[i].second;
		k %= a[i].first;
	}
	
	cout << ans.size() << endl;
	for (const int p : ans) cout << p << ' ';
}
