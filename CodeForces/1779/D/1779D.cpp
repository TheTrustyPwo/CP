#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a[n], b[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		int m; cin >> m;
		int r[m];
		for (int i = 0; i < m; i++) cin >> r[i];
		
		bool no = false;
		for (int i = 0; i < n; i++)
			if (b[i] > a[i]) no = true;
		if (no) { cout << "NO\n"; continue; }
		
		int mx[n]; mx[0] = b[0];
		for (int i = 1; i < n; i++) mx[i] = max(mx[i - 1], b[i]);
		
		unordered_map<int, int> mp;
		for (int i = 0; i < n; i++) {
			
		}
	}
}
