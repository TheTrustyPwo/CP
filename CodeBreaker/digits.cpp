#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, q;
ll pw[200005];

struct node {
	int s, e, m;
	ll val;
	node *l, *r;
	
	node(int S, int E) {
		s = S, e = E, m = (s + e) / 2;
		val = 0;
		if (s != e) {
			l = new node(s, m);
			r = new node(m + 1, e);
		}
	}
	
	void update(int X, int V) {
		if (s == e && e == X) val = V % m;
		else { 
			if (X <= m) l->update(X, V);
			else r->update(X, V);
			val = (l->val * pw[r->e - r->s + 1] + r->val) % m;
		}
	}
	
	ll query(int S, int E) {
		if (s == S && e == E) return val;
		else if (E <= m) return l->query(S, E);
		else if (S >= m + 1) return r->query(S, E);
		else return (l->query(S, m) * pw[E - m] + r->query(m + 1, E)) % m;
	}
} *root;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	pw[0] = 1; for (int i = 1; i <= n; i++) pw[i] = (pw[i - 1] * 10) % m;
	root = new node(1, n);
	for (int i = 1; i <= n; i++) { char ch; cin >> ch; root->update(i, ch - '0'); }
	cin >> q;
	while (q--) {
		int t, a, b; cin >> t >> a >> b;
		if (t == 1) cout << root->query(a, b) << "\n";
		else root->update(a, b);
	}
}
