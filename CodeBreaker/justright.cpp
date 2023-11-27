#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
int a[200005], pre[200005];

bool check(int m) {
	int res = 0; m++;
	for (int i = 1; i <= n; i++) {
		if (pre[i] < m) continue;
		int amt = upper_bound(pre, pre + i, pre[i] - m) - pre;
		res += amt;
	}
	return res <= k;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k; k--;
	for (int i = 0; i < n; i++) cin >> a[i];
	pre[0] = 0; for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
	
	int l = 1, r = pre[n];
	while (l < r) {
		int m = l + (r - l) / 2;
		if (check(m)) r = m;
		else l = m + 1;
	}

	cout << l;
}
