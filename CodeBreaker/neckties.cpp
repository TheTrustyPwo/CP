#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	pair<int, int> a[n + 1]; int b[n + 1], mp[n + 1];
	for (int i = 0; i <= n; i++) { cin >> a[i].first; a[i].second = i; }
	for (int i = 1; i <= n; i++) cin >> b[i];
	
	sort(a, a + n + 1); sort(b + 1, b + n + 1);
	for (int i = 0; i <= n; i++) mp[a[i].second] = i;
	
	int pre[n + 1]; pre[0] = 0;
	for (int i = 1; i <= n; i++) pre[i] = max(pre[i - 1], a[i - 1].first - b[i]);
	
	int suf[n + 2]; suf[n + 1] = 0;
	for (int i = n; i > 0; i--) suf[i] = max(suf[i + 1], a[i].first - b[i]);

	for (int i = 0; i <= n; i++) {
		cout << max(pre[mp[i]], suf[mp[i] + 1]) << ' ';
	}
}
