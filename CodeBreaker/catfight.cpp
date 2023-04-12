#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, p; cin >> n >> p;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	
	int start = 0, end = 0, sum = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		end++;
		while (sum >= p) {
			sum -= a[start];
			start++;
		}
		ans = max(ans, end - start);
	}
	
	cout << ans;
}
