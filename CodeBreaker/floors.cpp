#include <bits/stdc++.h>
using namespace std;

int p[10000000];

int find(const int &x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, c; cin >> n >> c;
	for (int i = 1; i <= n; i++) p[i] = i;
	while (c--) {
		int x; cin >> x;
		x = find(x);
		cout << x << '\n';
		p[x] = (x == 1 ? n : x - 1);
	}
}
