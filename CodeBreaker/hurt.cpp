#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b; cin >> a >> b;
	int ans = 0;
	for (int k = a; k <= b; k++) {
		int n = k;
		bool bl = true;
		while (n > 0) {
			if ((n % 10 == 0) || k % (n % 10) != 0) {
				bl = false;
				break;
			}
			n /= 10;
		}
		ans += bl;
	}
	cout << ans;
}
