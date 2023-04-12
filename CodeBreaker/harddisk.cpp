#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k, off;
vector<pair<int, int>> v, d;
map<int, int> m1, m2;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		if (b == 0) continue;
		if (a == 0) off += b;
		else v.push_back(make_pair(a, b));
	}
	
	n = v.size();
	int x = n / 2;
	
	m1[0] = 0;
	for (int i = 0; i < x; i++) {
		for (auto &[key, val] : m1){
			if (key + v[i].first > k) continue;
			m2[key + v[i].first] = max(m2[key + v[i].first], m1[key] + v[i].second);
		}
		for (auto &[key, val] : m2) m1[key] = max(m1[key], val);
		m2.clear();
	}
	
	for (auto p : m1) d.push_back(p);
	
	m1.clear();
	m1[0] = 0;
	for (int i = x; i < n; i++) {
		for (auto &[key, val] : m1) {
			if (key + v[i].first > k) continue;
			m2[key + v[i].first] = max(m2[key + v[i].first], m1[key] + v[i].second);
		}
		for (auto &[key, val] : m2) m1[key] = max(m1[key], val);
		m2.clear();
	}
	
	int stop = d.size() - 1, curind = 0, t = 0, ans = 0;
	v.clear();
	for (auto p : m1) v.push_back(p);
	reverse(v.begin(), v.end());
	
	for (auto &[key, val] : v) {
		while (curind + 1 <= stop && d[curind + 1].first + key <= k)
			t = max(t, d[++curind].second);
		ans = max(ans, t + val);
	}
	
	cout << ans + off;
}
