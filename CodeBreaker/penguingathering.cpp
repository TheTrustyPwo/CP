#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	
	int mn = 1e18;
	for (int i = 1; i <= 1000; i++) {
		int cost = 0;
		for (int j = 0; j < n; j++) cost += (a[j] - i) * (a[j] - i);
		mn = min(mn, cost);
	}
	
	cout << mn;
}
