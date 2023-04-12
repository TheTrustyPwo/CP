#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int ftm[100005], ftc[100005];

void update(int *t, int p, int k) {
	for (; p <= n; p += (p & -p)) t[p] += k;
}

void rangeUpdate(int l, int r, int k) {
	update(ftm, l, k);
	update(ftm, r + 1, -k);
	update(ftc, l, k * (l - 1));
	update(ftc, r + 1, -k * r);
}

int query(int *t, int p) {
	int sum = 0;
	for (; p; p -= (p & -p)) sum += t[p];
	return sum;
}

int prefixQuery(int p) {
	return query(ftm, p) * p - query(ftc, p);
}

int range(int l, int r) {
	return prefixQuery(r) - prefixQuery(l - 1);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		rangeUpdate(i, i, a);
	}
	
	int q; cin >> q;
	while (q--) {
		bool t; cin >> t;
		if (t) {
			int a, b, c; cin >> a >> b >> c; a++; b++;
			rangeUpdate(a, b, c);
		} else {
			int a, b; cin >> a >> b; a++; b++;
			cout << range(a, b) << endl;
		}
	}
}
