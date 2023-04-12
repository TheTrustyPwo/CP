#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pair<ll, ll> a[n];
	for (int i = 0; i < n; i++) cin >> a[i].first;
	for (int i = 0; i < n; i++) cin >> a[i].second;
	for (int i = 0; i < n; i++) pq.push(a[i]);
	
	ll skill = 0;
	priority_queue<ll> avail;
	while (k--) {
		while (!pq.empty() && pq.top().first <= skill) {
			avail.push(pq.top().second);
			pq.pop();
		}
		if (!avail.empty()) {
			skill += avail.top();
			avail.pop();
		}
	}
	
	cout << skill;
}
