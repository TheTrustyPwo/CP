#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int ftm[100005], ftc[100005];

int query(int p) {
	int m = 0, c = 0;
	for (int i = p; i; i -= (i & -i)) m += ftm[i];
	for (int i = p; i; i -= (i & -i)) c += ftc[i];
	return m * p + c;
}

void update(int l, int r, int v) {
	for (int i = l; i <= n; i += (i & -i)) ftm[i] += v;
	for (int i = r + 1; i <= n; i += (i & -i)) ftm[i] -= v;
	for (int i = l; i <= n; i += (i & -i)) ftc[i] -= v * (l - 1);
	for (int i = r + 1; i <= n; i += (i & -i)) ftc[i] += r * v;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		update(i, i, a);
	}
	
	int q; cin >> q;
	while (q--) {
		bool t; cin >> t;
		if (t) {
			int a, b, c; cin >> a >> b >> c; a++; b++;
			update(a, b, c);
		} else {
			int a, b; cin >> a >> b; b++;
			int ans = query(b) - query(a);
			cout << ans << endl;
		}
	}
}
