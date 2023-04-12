#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n, a, cur = 0, mx = 0; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == -1) mx = max(mx, cur), cur = 0;
		else cur += a;
	}
	
	cout << max(mx, cur);
}
