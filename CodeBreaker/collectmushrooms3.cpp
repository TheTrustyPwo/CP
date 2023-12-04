#include <bits/stdc++.h>
using namespace std;

struct Vertex {
	int s, e, val;
	Vertex *l, *r;
	
	Vertex(int S, int E) {
		s = S, e = E;
		val = 1e9;
		if (s != e) {
			int m = (s + e) / 2;
            l = new Vertex(s, m);
            r = new Vertex(m + 1, e);
		}
	}
    
    void update(int k, int x) {
        if (s == e) val = x;
        else {
			int m = (s + e) / 2;
            if (k <= m) l->update(k, x);
            else r->update(k, x);
            val = min(l->val, r->val);
        }
    }

    int query(int S, int E) {
		if (s == S && e == E) return val;
		int m = (s + e) / 2;
		if (E <= m) return l->query(S, E);
		else if (S >= m + 1) return r->query(S, E);
		else return min(l->query(S, m), r->query(m + 1, E));
    }
} *v;

int n, q, t, x, y, d[500005];
vector<int> num;
vector<pair<int, int>> vc;
int s[500005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		vc.push_back(make_pair(d[i], i));
	}
	
	sort(vc.begin(), vc.end());
	
	int id = -1;
	for (const pair<int, int> &p : vc) {
		id++; num.push_back(p.first);
		s[id] = p.second;
		d[p.second] = id;
	}
	
	v = new Vertex(0, id);
	for (int i = 0; i <= id; i++) v->update(i, s[i]);
	
	while (q--) {
		cin >> t >> x >> y;
		if (t == 0) {
            int lo = lower_bound(num.begin(), num.end(), x) - num.begin();
            int hi = upper_bound(num.begin(), num.end(), y) - num.begin() - 1;
            if (hi < lo) cout << "-1\n";
            else cout << v->query(lo, hi) << '\n';
		} else {
            s[d[x]] = y;
            s[d[y]] = x;
			v->update(d[x], y);
			v->update(d[y], x);
			swap(d[x], d[y]);
		}
	}
}
