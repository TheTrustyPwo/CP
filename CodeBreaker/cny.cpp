#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x % 2 == 0) v.push_back(x);
	}
	
	sort(v.begin(), v.end(), greater<int>());
	
	int ans = 0;
	for (int i = 0; i < min(m, (int) v.size()); i++) ans += v[i];
	cout << ans;
}
