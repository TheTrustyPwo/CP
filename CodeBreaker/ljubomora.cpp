#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, a[300000];

bool valid(int x) {
	int res = 0;
	for (int i = 0; i < m; i++)
		res += (a[i] / x + (a[i] % x != 0));
	return res <= n;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> a[i];
	int l = 1, r = *max_element(a, a + m);
	while (l < r) {
		int mid = (l + r) / 2;
		if (valid(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l;
}
