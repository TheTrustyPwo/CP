#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 300005;

int m, s, k, a[MAXN], b[MAXN], preb[MAXN];

int count(int d) {
	int cnt = 0;
	for(int i = 0; i < m; i++) {
		if (a[i] >= d) break;
		int combos_to_buy = upper_bound(b, b + s, d - a[i]) - b;
		cnt += combos_to_buy;
	}
	return cnt;
}

int sum(int d) {
	int sum = 0;
	for (int i = 0; i < m; i++) {
		if (a[i] >= d) break;
		int buy = upper_bound(b, b + s, d - a[i]) - b;
		sum += (a[i] * buy + preb[buy - 1]);
	}
	return sum;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> m >> s >> k;
	for (int i = 0; i < m; i++) cin >> a[i];
	for (int i = 0; i < s; i++) cin >> b[i];
	sort(a, a + m);
	sort(b, b + s);
	
	preb[0] = b[0];
	for (int i = 1; i < s; i++) preb[i] = b[i] + preb[i - 1];
	
	int l = 0, r = 1e18;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (count(mid) >= k) r = mid;
		else l = mid + 1;
	}

	int ans = sum(l - 1) + (k - count(l - 1)) * l;
	cout << ans;
}
