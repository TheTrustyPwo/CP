#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (abs(n - 69) < abs(n - 420)) cout << 69 << '\n';
		else cout << 420 << '\n';
	}
}
