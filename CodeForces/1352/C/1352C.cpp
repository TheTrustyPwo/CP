#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		cout << k + (k - 1) / (n - 1) << '\n';
	}
}
