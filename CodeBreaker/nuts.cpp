#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, total = 0; cin >> n;
	int z[n];
	pair<int, int> a[n];
	int b[n];
	pair<int, int> c[n];
	for (int i = 0; i < n; i++) {
		cin >> z[i];
		total += z[i];
	}
	for (int i = 0; i < n; i++) cin >> b[i];
	
	for (int i = 0; i < n; i++) a[i] = make_pair(z[i], b[i]);
	for (int i = 0; i < n; i++) c[i] = make_pair(b[i], z[i]);
	
	sort(c, c + n, greater<pair<int, int>>());
	int k = 0, space = 0;
	set<pair<int, int>> chosen;
	for (int i = 0; i < n; i++) {
		space += c[i].first;
		chosen.insert(make_pair(c[i].second, c[i].first));
		k++;
		if (space >= total) break;
	}
	
	for (int i = k; i < n; i++) {
		if (c[i].second > chosen.begin()->first && space - chosen.begin()->second + c[i].first >= total) {
			space = space - chosen.begin()->second + c[i].first;
			chosen.erase(chosen.begin());
			chosen.insert(make_pair(c[i].second, c[i].first));
		}
	}
	
	int ans = 0;
	for (const pair<int, int> x : chosen) ans += x.first;
	
	cout << k << ' ' << total - ans;
}
