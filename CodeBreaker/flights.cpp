#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, e, x, y;
int p[100005], d1[100005], d2[100005];
pair<int, int> f[100005];
vector<pair<int, int>> g[100005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> e;
	for (int i = 0; i < n; i++) cin >> p[i];
	cin >> x >> y;
	for (int i = 0; i < e; i++) {
		int a, b, w; cin >> a >> b >> w;
		g[b].push_back(make_pair(a, w));
	}
	
	fill(d1, d1 + n, 1e16); d1[0] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(0, 0);
	while (!pq.empty()) {
		int du = pq.top().first, u = pq.top().second; pq.pop();
		if (du > d1[u]) continue;
		for (const pair<int, int> &v : g[u]) {
			if (d1[u] + v.second < d1[v.first]) {
				d1[v.first] = d1[u] + v.second;
				pq.emplace(d1[v.first], v.first);
			}
		}
	}
	
	while (!pq.empty()) pq.pop();
	fill(d2, d2 + n, 1e16); d2[x] = 0;
	pq.emplace(0, x);
	while (!pq.empty()) {
		int du = pq.top().first, u = pq.top().second; pq.pop();
		if (du > d2[u]) continue;
		for (const pair<int, int> &v : g[u]) {
			if (d2[u] + v.second < d2[v.first]) {
				d2[v.first] = d2[u] + v.second;
				pq.emplace(d2[v.first], v.first);
			}
		}
	}
	
	for (int i = 1; i < n; i++) {
		if (d2[i] == 1e16) f[i] = make_pair(0, i);
		else f[i] = make_pair(d1[i] - d1[y] - d2[i], i);
	}
	sort(f + 1, f + n, greater<pair<int, int>>());
	
	int pop = 0, cur = f[1].first, pft = 0, ans = 0;
	for (int i = 1; i < n; i++) {
		pft -= pop * (cur - f[i].first);
		pft += p[f[i].second] * f[i].first;
		ans = max(ans, pft);
		pop += p[f[i].second];
		cur = f[i].first;
	}
	
	cout << ans;
}
