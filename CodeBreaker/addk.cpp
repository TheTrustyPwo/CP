#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k, q, a[100005];
int fw1[100005], fw2[100005], fw3[100005];

void update(int *t, int p, int v) {
	while (p <= n) {
		t[p] += v;
		p += p & -p;
	}
}

void update(int p, int v) {
	update(fw1, p, v);
	update(fw2, p, p * v);
	update(fw3, p, (n - p + 1) * v);
}

int query(int *t, int p) {
	int res = 0;
	while (p) {
		res += t[p];
		p -= p & -p;
	}
	return res;
}

int query(int *t, int l, int r) {
	return query(t, r) - query(t, l - 1);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(i, a[i]);
	}
	
	cin >> q;
	while (q--) {
		int t, b[k]; cin >> t;
		if (t == 1) {
			for (int i = 0; i < k; i++) cin >> b[i];
			int tmp = a[b[0]];
			for (int i = 1; i < k; i++)
				update(b[i - 1], a[b[i]] - a[b[i - 1]]), a[b[i - 1]] = a[b[i]];
			update(b[k - 1], tmp - a[b[k - 1]]); a[b[k - 1]] = tmp;
		} else {
			int l, r, m; cin >> l >> r >> m;
			int sum = 0;
			sum += query(fw2, l, l + m - 2) - ((l - 1) * query(fw1, l, l + m - 2));
			sum = sum + query(fw3, r - m + 2, r) - ((n - r) * query(fw1, r - m + 2, r));
			sum += m * query(fw1, l + m - 1, r - m + 1);
			cout << sum << '\n';
		}
	}
}
