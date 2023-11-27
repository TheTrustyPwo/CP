#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	
	int ans = 0;
	set<pair<int, int>> s;
	s.insert(make_pair(0, 1));
	s.insert(make_pair(a[0], 1));
	
	for (int i = 1; i < n; i++) {
		auto it = --(s.lower_bound(make_pair(a[i], 0)));
		pair<int, int> p = *it;
		ans += p.second;
		s.erase(it);
		s.insert(make_pair(p.first, p.second + 1));
		s.insert(make_pair(a[i], p.second + 1));
	}
	
	cout << ans;
}
