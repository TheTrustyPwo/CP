#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int a[n], ops[n]; for (int i = 0; i < n; i++) cin >> a[i];
	
	int ans = 0, sum = 0, range = 0;
	for (int i = n - 1; i >= 0; i--) {
		sum -= range;
		if (n - i > k) range -= ops[i + k];
		a[i] = max(a[i] - sum, 0ll);
		if (i < k - 1) {
			int tmp = i + 1;
			ops[i] = (a[i] / tmp) + (a[i] % tmp != 0);
			sum += ops[i] * tmp;
		} else {
			ops[i] = (a[i] / k) + (a[i] % k != 0);
			sum += ops[i] * k;
		}
		ans += ops[i];
		range += ops[i];
	}
	
	cout << ans;
}
