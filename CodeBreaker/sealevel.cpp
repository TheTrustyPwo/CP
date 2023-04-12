#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool visited[1000005];
vector<pair<ll, ll>> g[1000005];
ll diff[1000005];

void dfs(ll source, ll d) {
	if (visited[source]) return;
	visited[source] = true;
	diff[source] = d;
	for (pair<ll, ll> v : g[source]) dfs(v.first, d + v.second);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n, q; cin >> n;
	for (ll i = 1; i < n; i++) {
		int a, b, w; cin >> a >> b >> w;
		g[a].push_back(make_pair(b, w));
		g[b].push_back(make_pair(a, -w));
	}
	diff[1] = 0;
	dfs(1, 0);
	cin >> q;
	while (q--) {
		ll a, b; cin >> a >> b;
		cout << diff[b] - diff[a] << endl;
	}
}
