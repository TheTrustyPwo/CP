#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n,G = 0, x, m;
	ll sum0 = 0, sum1 = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	while (m--) {
		cin >> x;
		G = __gcd(G,x);
	}
 
	for (int i = 0; i < G; i++) {
		ll tmp1 = -1e18, tmp0 = 0, P1, P0; 
		for (int k = i; k < n; k += G) {
			swap(tmp1, P1);
			swap(tmp0, P0);
			tmp1 = max(P1 + a[k],P0 - a[k]);
			tmp0 = max(P0 + a[k],P1 - a[k]);
		}
		sum0 += tmp0;
		sum1 += tmp1;
 
	}
	cout << max(sum0, sum1);
}
