#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, t, k, l;
int runway[100005];
int landing[100005];
multiset<pair<int, int>> rem;
queue<pair<int, int>> used;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> t >> k >> l;
	for (int i = 0; i < m; i++) cin >> landing[i];
	sort(landing, landing + m);
	
	for (int i = 0; i < n; i++) rem.insert(make_pair(0, i));
	
	int ans = 0;
	for (int i = 0; i < m; i++) {
		while (!used.empty() && runway[used.front().second] <= landing[i]) {
			rem.insert(used.front());
			used.pop();
		}
		
		if (rem.empty()) {
			cout << -1;
			return 0;
		}
		
		int cmp = landing[i] % k;
		auto it = rem.upper_bound({cmp, 1e9});

		pair<int, int> v;
		if (it == rem.begin()) {
			v = *(rem.rbegin());
		} else {
			v = *(--it);
		}
		
		
		int idx = v.second;
		ans += (landing[i] - runway[idx]) / k;
		runway[idx] = landing[i] + l;
		rem.erase(v);
		used.emplace(runway[idx] % k, idx);
	}
	
	for (int i = 0; i < n; i++) ans += (t - runway[i]) / k;
	cout << ans;
}
