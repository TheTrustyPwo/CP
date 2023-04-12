#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
	int s, e, m;
	ll mx, pfx, sfx, sm;
	node *l, *r;
	
	node(int S, int E) {
		s = S, e = E, m = (s + e) / 2;
		mx = 0, pfx = 0, sfx = 0, sm = 0;
		if (s != e) {
			l = new node(s, m);
			r = new node(m + 1, e);
		}
	}
	
	void update(int X, ll V) {
		if (s == e && e == X) {
			sm = V;
			mx = max(V, 0ll);
			pfx = max(V, 0ll);
			sfx = max(V, 0ll);
		} else { 
			if (X <= m) l->update(X, V);
			else r->update(X, V);
			pfx = max(l->pfx, l->sm + r->pfx);
			sfx = max(r->sfx, r->sm + l->sfx);
			sm = l->sm + r->sm;
			mx = max({pfx, sfx, l->mx, r->mx, l->sfx + r->pfx});
		}
	}
	
	int query() {
		return mx;
	}
} *root;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q; cin >> n;
	root = new node(0, n - 1);
	for (int i = 0; i < n; i++) { int a; cin >> a; root->update(i, a); }
	cout << root->query() << "\n";
	cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		root->update(a, b);
		cout << root->query() << "\n";
	}
}
