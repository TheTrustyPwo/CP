#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> dsu;

int find(int n) {
	if (dsu[n] == n) return n;
	return dsu[n] = find(dsu[n]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) {
		dsu[a] = b;
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, c; cin >> n >> c;
	for (int i = 0; i <= n; i++) dsu.push_back(i);
	while (c--) {
		int q; cin >> q;
		int p = find(q);
		cout << p << "\n";
		merge(p, (p - 1 == 0 ? n : p - 1));
	}
}
