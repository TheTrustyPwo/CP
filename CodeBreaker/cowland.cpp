#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;

int n, q, e[MAXN], parent[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN], t[262144], cur = 1;
vector<int> g[MAXN];

void build() {
    for (int i = n - 1; i; i--) t[i] = t[i << 1] ^ t[i << 1 | 1];
}

void update(int p, int v) {
	for (t[p += n] = v; p > 1; p >>= 1) t[p >> 1] = t[p] ^ t[p ^ 1];
}
	
int query(int l, int r) {
	int res = 0;
	for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res ^= t[l++];
		if (r & 1) res ^= t[--r];
	}
	return res;
}

int dfs(int v) {
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

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> t[n + i];
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    build();
	memset(heavy, -1, sizeof(heavy));
	dfs(0);
	decompose(0, 0);

    while (q--) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 1) {
            update(pos[a - 1], b);
        } else {
			a--; b--; int res = 0;
			if (depth[a] > depth[b]) swap(a, b);
			for (; head[a] != head[b]; b = parent[head[b]]) {
				if (depth[head[a]] > depth[head[b]]) swap(a, b);
				res ^= query(pos[head[b]], pos[b]);
			}
			if (depth[a] > depth[b]) swap(a, b);
			res ^= query(pos[a] + 1, pos[b]);
			cout << res << "\n";
        }
    }
}