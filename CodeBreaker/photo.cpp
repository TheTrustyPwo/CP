#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, s; cin >> n >> s;
	int total = n * s;
	int cnt[n]{}; set<int> cls;
	multiset<int> frame;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < s; j++) {
			int x; cin >> x;
			v.emplace_back(x, i);
		}
	}
	
	sort(v.begin(), v.end());
	
	int left = 0, right = 0, ans = 1e9;
	while (true) {
		while (cls.size() < n && right < total) {
			frame.insert(v[right].first);
			cnt[v[right].second]++;
			cls.insert(v[right].second);
			right++;
		}
		if (cls.size() < n) break;
		ans = min(ans, *frame.rbegin() - *frame.begin());
		
		if (cnt[v[left].second] == 1) cls.erase(v[left].second);
		cnt[v[left].second]--;
		frame.erase(frame.find(v[left].first));
		left++;
	}
	
	cout << ans;
}
