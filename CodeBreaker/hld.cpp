#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;

int n, q, w[MAXN], parent[MAXN], sz[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN], t[262144], cur = 1;
vector<int> g[MAXN];

struct node {
	int s, e, m, val, lazy;
	node *l, *r;
	
	node(int S, int E) {
		s = S, e = E, m = (s + e) / 2;
		val = lazy = 0;
	}
	
	void create() {
		if (s != e) {
			l = new node(s, m);
			r = new node(m + 1, e);
		}
	}
	
	void propogate() {
		if (l == nullptr) create();
		if (lazy == 0) return;
		val += lazy * (e - s + 1);
		if (s != e) {
			l->lazy += lazy;
			r->lazy += lazy;
		}
		lazy = 0;
	}
	
	void update(int S, int E, int V) {
		if (l == nullptr) create();
		if (s == S && e == E) lazy += V;
		else {
			if (E <= m) l->update(S, E, V);
			else if (m < S) r->update(S, E, V);
			else l->update(S, m, V), r->update(m + 1, E, V);
			l->propogate(), r->propogate();
			val = l->val + r->val;
		}
	}
	
	int query(int S, int E) {
		if (l == nullptr) create();
		propogate();
		if (s == S && e == E) return val;
		else if (E <= m) return l->query(S, E);
		else if (S >= m + 1) return r->query(S, E);
		else return l->query(S, m) + r->query(m + 1, E);
	}
} *root;

int dfs(int v) {
    sz[v] = 1;
    for (const int u : g[v]) {
        if (u == parent[v]) continue;
        depth[u] = depth[v] + 1;
        g[u].erase(find(all(g[u]), v));
        dfs(u); sz[v] += sz[u];
        if (sz[u] > sz[g[v][0]]) swap(u, g[v][0]);
    }

	int size = 1, mchild = 0;
	for (const int u : g[v]) {
		if (u == parent[v]) continue;
		parent[u] = v, depth[u] = depth[v] + 1;
		int csize = dfs(u);
		size += csize;
		if (csize > mchild) mchild = csize, heavy[v] = u;
	}
	return size;
}

void decompose(int v, int h) {
	head[v] = h, pos[v] = cur++;
	if (heavy[v] != -1) decompose(heavy[v], h);
	for (const int u : g[v])
		if (u != parent[v] && u != heavy[v])
			decompose(u, u);
}

void reroot(int u, int v) {

}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 2; i <= n; i++) {
        cin >> parent[i];
        g[parent[i]].push_back(i);
        g[i].push_back(parent[i]);
    }

    memset(heavy, -1, sizeof(heavy));
	dfs(1);
	decompose(1, 1);

    cin >> q;
    while (q--) {
        int t, u, v, k; cin >> t;
        if (t == 1) {
            cin >> u;
        } else if (t == 2) {
            cin >> u >> v >> k;
        } else if (t == 3) {
            cin >> u >> k;
        } else if (t == 4) {
            cin >> u >> v;
        } else if (t == 5) {
            cin >> u;
        }
    }
}