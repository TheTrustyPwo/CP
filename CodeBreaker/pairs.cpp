#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, a[200005];

bool check(int k) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int c = (k / a[i]) + (k % a[i] != 0);
		int x = n - (lower_bound(a, a + n, c) - a);
		cnt += min(x, n - i);
	}
	cout << cnt << ' ';
	return cnt >= k;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	sort(a, a + n);
	
	int l = 0, r = 1e9 + 1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	
	cout << l;
}
