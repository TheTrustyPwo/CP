#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[1005]{};
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (x == 1) v.push_back(i);
		a[x] = max(a[x], i);
	}
	
	int ans = -1;
	for (int i = 1; i <= 1000; i++) for (int j = i + 1; j <= 1000; j++) {
		if (a[i] != 0 && a[j] != 0 && __gcd(i, j) == 1)
			ans = max(ans, a[i] + a[j]);
	}
	
	sort(v.begin(), v.end(), greater<int>());
	if (v.size() >= 2) ans = max(ans, v[0] + v[1]);	
	cout << ans;
}
