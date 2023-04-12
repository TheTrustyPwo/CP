#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200005;

int n, c, q, pv[MAXN], m[MAXN], ans[MAXN], t[524288];
vector<tuple<int, int, int>> v;

void update(int p, int v) {
	for (t[p += n] = v; p > 1; p >>= 1) t[p >> 1] = min(t[p], t[p ^ 1]);
}
	
int query(int l, int r) {
	int res = 1e9;
	for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = min(res, t[l++]);
		if (r & 1) res = min(res, t[--r]);
	}
	return res;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> c >> q;
	memset(m, -1, sizeof(m));
	fill(t, t + 524288, 1e9);
	
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		pv[i] = m[x];
		m[x] = i;
	}
	
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		v.push_back(make_tuple(r, l, i));
	}
	
	sort(v.begin(), v.end()); int pr = -1;
	for (int i = 0; i < q; i++) {
		int id, l, r; tie(r, l, id) = v[i];
		for (int i = pr + 1; i <= r; i++) {
			if (pv[i] == -1) continue;
			update(pv[i], i - pv[i]);
		}
		
		pr = r;
		int tmp = query(l, r);
		ans[id] = (tmp == 1e9) ? -1 : tmp;
	}
	
	for (int i = 0; i < q; i++) cout << ans[i] << "\n";
}
