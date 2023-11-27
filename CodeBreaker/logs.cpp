#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k, a[200005];

bool check(int m) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += (a[i] / m + (a[i] % m != 0));
	}
	return res <= (n + k);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	int l = 1, r = accumulate(a, a + n, (long long) 0);
	while (l < r) {
		int m = l + (r - l) / 2;
		if (check(m)) r = m;
		else l = m + 1;
	}
	
	cout << l;
}
