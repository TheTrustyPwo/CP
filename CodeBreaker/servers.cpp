#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int LG = 18;
vector<int> adj[N];

struct segtree {
  int n;
  vector<int> ch, seg;
  segtree() {}
  void upd(int l, int r, int k, int x, int v) {
    if (r < x || x < l) return;
    if (x <= l && r <= x) {
      seg[k] += v;
      return;
    }
    int m = (l+r) / 2;
    upd(l, m, k*2, x, v);
    upd(m+1, r, k*2+1, x, v);
    seg[k] = seg[k*2] + seg[k*2+1];
  }
  int qry(int l, int r, int k, int x) {
    if (r < x) return 0;
    if (x <= l) return seg[k];
    int m = (l+r) / 2;
    return qry(l, m, k*2, x) + qry(m+1, r, k*2+1, x);
  }
  void upd(int t) {
    int i = lower_bound(ch.begin(), ch.end(), t) - ch.begin();
    upd(0, n-1, 1, i, 1);
  }
  int qry(int t) {
    int i = lower_bound(ch.begin(), ch.end(), t) - ch.begin();
    return qry(0, n-1, 1, i);
  }
  void init() {
    seg.resize(4*n);
    fill(seg.begin(), seg.end(), 0);
  }
} seg[N];

// start lca
int lca_par[LG][N], depth[N];

int jump(int u, int d) {
  if (d < 0)
    return u;
  for (int i = 0; i < LG; i++)
    if (d >> i & 1)
      u = lca_par[i][u];
  return u;
}

int lca(int u, int v) {
  if (depth[u] > depth[v])
    swap(u, v);
  v = jump(v, depth[v] - depth[u]);
  if (u == v)
    return u;
  for (int i = LG-1; i >= 0; i--)
    if (lca_par[i][u] != lca_par[i][v])
      u = lca_par[i][u], v = lca_par[i][v];
  return lca_par[0][u];
}

void dfs(int u, int p) {
  for (int v: adj[u]) if (v != p) {
    depth[v] = depth[u] + 1;
    lca_par[0][v] = u;
    dfs(v, u);
  }
}

int s[N], par[N], vis[N], cd_depth[N];

int getSz(int u, int p) {
  s[u] = 1;
  for (int v: adj[u])
    if (v != p && !vis[v])
      s[u] += getSz(v, u);
  return s[u];
}

int findCen(int u, int p, int n) {
  for (int v: adj[u])
    if (v != p && !vis[v] && s[v] > n/2)
      return findCen(v, u, n);
  return u;
}

void decompose(int c, int p) {
  c = findCen(c, -1, getSz(c, -1));
  par[c] = p;
  cd_depth[c] = ~p ? cd_depth[p] + 1 : 0;
  vis[c] = 1;
  for (int v: adj[c])
    if (!vis[v])
      decompose(v, c);
  vis[c] = 0;
}
// end centroid decomposition

// start hld
int hvy[N], root[N];

int init_hld(int u, int p) {
  s[u] = 1;
  hvy[u] = -1;
  root[u] = u;
  for (int v: adj[u]) {
    if (v != p) {
      s[u] += init_hld(v, u);
      if (hvy[u] < 0 || s[hvy[u]] < s[v])
        hvy[u] = v;
    }
  }
  return s[u];
}
// end hld

int hi[N][2], lo[N]; // walk up using edges with (decreasing / increasing) indices or down using edges with decreasing indices
int ind[N], curt = 0; // time when u and lca_par[0][u] where connected

void init(int n, vector<pair<int,int>> e) {
  for (auto [u, v]: e) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  // cd
  decompose(1, -1);
  for (int i = 1; i <= n; i++) {
    for (int j: adj[i]) {
      if (cd_depth[j] > cd_depth[i])
        seg[i].n++;
    }
    seg[i].init();
  }
  // lca
  dfs(1, -1);
  for (int i = 1; i < LG; i++)
    for (int j = 1; j <= n; j++)
      lca_par[i][j] = lca_par[i-1][lca_par[i-1][j]];
  // hld
  init_hld(1, -1);
  for (int i = 1; i <= n; i++)
    if (lca_par[0][i] == 0 || hvy[lca_par[0][i]] != i)
      for (int j = i; j != -1; j = hvy[j])
        root[j] = i;

  for (int i = 1; i <= n; i++)
    hi[i][0] = hi[i][1] = i, ind[i] = N+1, lo[i] = i;
}

int lower(int u, int v) {
  return depth[u] > depth[v] ? v : u;
}

int higher(int u, int v) {
  return depth[u] < depth[v] ? v : u;
}

// last node on the path from u to v
int last_node(int u, int v) {
  if (u == v)
    return u;
  int l = lca(u, v);
  if (l != v)
    return lca_par[0][v];
  return jump(u, depth[u] - depth[l] - 1);
}

// last node on the path from u to v
int first_node(int u, int v) {
  return last_node(v, u);
}

// when was this edge created?
int get_ind(int u, int v) {
  return u == v ? 0 : ind[higher(u, v)];
}

// is there a path from v to u where the indices of all edges increase
bool data(int u, int v) {
  if (u == v)
    return 1;
  int l = lca(u, v);
  if (lower(hi[u][0], l) != hi[u][0]) // walk down using increasing labels
    return 0;
  int x = v, y = -1;
  while (root[x] != root[l])
    y = root[x], x = lca_par[0][root[x]];
  // there is a light edge on the path from v to l -> we updated the whole subtree containing v already
  if (x != v && lower(hi[v][1], x) != hi[v][1])
    return 0;
  // we have to walk from x to l over heavy edges and we might have to check a light edge
  if (higher(lo[l], x) != lo[l] || (x != l && y != -1 && get_ind(y, x) > ind[x]))
    return 0;
  int pu = last_node(u, l), pv = last_node(v, l);
  return u == l || v == l || ind[pu] > ind[pv];
}

void xchg(int u, int v) {
  ++curt;
  if (cd_depth[u] > cd_depth[v])
    swap(u, v);
  if (depth[u] > depth[v])
    swap(u, v);
  ind[v] = curt;

  hi[v][0] = hi[u][0];
  if (hvy[u] != v) {
    function<void(int,int,int)> mrk = [&](int x, int y, int t) {
      hi[x][1] = u;
      for (int z: adj[x])
        if (z != y && get_ind(x, z) < t)
          mrk(z, x, get_ind(x, z));
    };
    mrk(v, u, curt);
  } else {
    lo[u] = lo[v];
  }

  if (cd_depth[u] > cd_depth[v])
    swap(u, v);
  seg[u].ch.push_back(curt);
  // update segment tree
  int c = u;
  while (c > 0) {
    if (data(u, c)) { // walk from c to u and then over the new edge
      int fst = first_node(c, u);
      if (fst == c)
        fst = v;
      int t = get_ind(c, fst);
      seg[c].upd(t);
    }
    c = par[c];
  }
}

int count(int u) {
  int c = u, r = 0;
  while (c > 0) {
    if (data(c, u)) {
      int lst = last_node(u, c);
      int t = get_ind(lst, c) + 1;
      r += seg[c].qry(t) + 1;
    }
    c = par[c];
  }
  return r;
}

int main() {
  int n, q; cin >> n >> q;
  vector<pair<int,int>> e(n-1);
  vector<array<int,3>> qr(n+q-1);
  for (int i = 0, j = 0; i < n+q-1; i++) {
    char t; int u, v = 0; cin >> t >> u;
    if (t != 'C')
      cin >> v;
    qr[i] = {t == 'C' ? 2 : (t == 'S' ? 0 : 1), u, v};
    if (t == 'S')
      e[j++] = make_pair(u, v);
  }
  init(n, e);
  for (int i = 0; i < n+q-1; i++) {
    int t = qr[i][0], u = qr[i][1], v = qr[i][2];
    if (t == 0) {
      xchg(u, v);
    } else if (t == 1) {
      bool b = data(u, v);
      cout << (b ? "yes\n" : "no\n");
    } else {
      int d = count(u);
      cout << d << "\n";
    }
  }
}
