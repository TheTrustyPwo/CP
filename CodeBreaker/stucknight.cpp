#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int p[10000000], n, c;

int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> c;
	for (int i = 1; i <= n; i++) p[i] = i;
	while (c--) {
		int x; cin >> x;
		x = find(x);
		cout << x << '\n';
		p[x] = (x == 1 ? n : x - 1);
	}
}
