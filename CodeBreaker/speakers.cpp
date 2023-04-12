#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	pair<int, int> a[n];
	
	for (int i = 0; i < n; i++) {
		int d, r; cin >> d >> r;
		a[i] = make_pair(max(0, d - r), min(m, d + r));
	}
	
	sort(a, a + n, &cmp);
	
	int ans = 1, cur = a[0].second;
	for (int i = 1; i < n; i++) {
		if (a[i].first <= cur) continue;
		cur = a[i].second;
		ans++;
	}
	
	cout << ans;
}
