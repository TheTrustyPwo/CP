#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, o, t, sum, ans, a[40], c[1050000];
bitset<20> b;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m; o = n / 2; t = n - o;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = 0; i < (1 << o); i++) {
		b = bitset<20>(i);
		for (int j = 0; j < o; j++)
			if (b.test(j)) c[i] += a[j];
	}
	
	sort(c, c + (1 << o));
	
	for (int i = 0; i < (1 << t); i++) {
		b = bitset<20>(i), sum = 0;
		for (int j = 0; j < t; j++)
			if (b.test(j)) sum += a[o + j];
		ans += upper_bound(c, c + (1 << o), m - sum) - c;
	}
	
	cout << ans;
}
