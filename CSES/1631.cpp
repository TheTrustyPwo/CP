#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int mx = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		mx = max(mx, x);
		sum += x;
	}
	
	cout << max(sum, mx * 2);
}
