#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	map<int, bool> b;
	for (int i = 0; i < m; i++) {
		int e; cin >> e;
		b[e] = 1;
	}
	
	reverse(a, a + n);
	for (auto e : a)
		if (b[e]) cout << e << ' ';
}
