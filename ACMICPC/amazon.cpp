#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;

vector<int> g[3005];
vector<pair<int,int> >v;
map<int, int> mp, mp2;
set<int> s;

int dp[2005][1005];

void dfs(int u) {
	dp[u][0] = u;
	while(!g[u].empty()){
		int a = g[u].back();
		
		g[u].pop_back();
		dfs(a);
		for (int i = 1003; i >=1 ; i--)
			dp[u][i] = max(dp[u][i], dp[a][i - 1]);
	}
	
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		v.push_back({l,r});
		s.insert(l); s.insert(r);
	}
	
	int tmp = 1;
	for (const int x : s) {
		mp[x] = tmp;
		mp2[tmp] = x;
		tmp++;
	}
	
	for (int i = 0; i < v.size(); i++)
		g[mp[v[i].first]].push_back(mp[v[i].second]);

	memset(dp, -1, sizeof(dp));

	dfs(1);
	
	int q; cin >> q;
	while (q--) {
		int x, u, v; cin >> x >> u >> v;
		x = mp[x];
		int mx = -1;
		for (int i = u; i <= v; i++) {
			mx = max(mx, dp[x][i]);
		}
		if (mx == -1) cout << -1 << ' ';
		else cout << mp2[mx] << ' ';
	}
}
