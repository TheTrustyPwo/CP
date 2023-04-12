#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		for (int i = 0; i < (n + 1) / 2; i++) {
			if (n - i == i + 1) cout << i + 1 << ' ';
			else cout << n - i << ' ' << i + 1 << ' ';
		}
		cout << '\n';
	}
}
