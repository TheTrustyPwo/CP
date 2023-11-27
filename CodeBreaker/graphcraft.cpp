#include <bits/stdc++.h>
#include "graphcraft.h"
using namespace std;
typedef long long ll;

const int m = 1e9 + 7;

vector<int> topo;
vector<int> g[100005];
int valid[100005], visited[100005];

bool check(int v, int c) {
	if (v == c) return true;
	visited[v] = -1;
	for (int u : g[v]) {
		if (visited[u] == -1) return false;
		else if (visited[u] == 0 && !check(u, c)) return false;
	}
	visited[v] = 1;
	return true;
}

void dfs(int v) {
	valid[v] = true;
	for (const int &u : g[v]) if (!valid[u]) dfs(u);
	topo.push_back(v);
}

void invalidate(int v) {
	visited[v] = true;
	valid[v] = false;
	for (const int &u : g[v]) if (!visited[u]) dfs(u);
}

int graphcraft(int n, int c, vector<pair<int, int>> V[]) {
	for (int i = 0; i < n; i++) {
		for (const auto &p : V[i]) {
			g[p.first].push_back(i);
		}
	}
	
	if (!check(0, c)) {
		return -1;
	}
	
	fill(visited, visited + n, 0);
	dfs(0); reverse(topo.begin(), topo.end());
	for (int i = 1; i < n; i++) {
		if (!valid[i] && !visited[i]) invalidate(i);
	}
	
	ll d[n]; fill(d, d + n, 0); d[0] = 1ll;
	for (const ll &u : topo) {
		if (!valid[u]) return -1;
		for (const pair<ll, ll> &p : V[u]) {
			d[u] = (d[u] + (d[p.first] * p.second) % m) % m;
		}
		if (u == c) break;
	}
	
	return d[c];
}
