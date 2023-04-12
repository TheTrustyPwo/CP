#include <bits/stdc++.h>
using namespace std;
#define int long long

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

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q; cin >> n >> q;
	root = new node(1, n);
	while (q--) {
		int t, a, b, c; cin >> t;
		if (t == 1) {
			cin >> a >> b >> c;
			root->update(a, b, c);
		} else {
			cin >> a >> b;
			cout << root->query(a, b) << "\n";
		}
	}
}
