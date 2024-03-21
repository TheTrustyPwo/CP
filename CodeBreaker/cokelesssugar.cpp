#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m; m++;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, greater<int>());
	
	if (a[0] <= 0) {
		int end = n - m;
		
		int cur = 0, ans = 0;
		for (int i = 0; i < m; i++) {
			cur = 0;
			for (int j = i; j < end; j += m) {
				cur += a[j];
				ans += cur;
			}
		}
		
		cout << ans;
		return 0;
	}
	
	int neg = n - 1;
	for (int i = 0; i < n; i++) if (a[i] < 0) { neg = i; break; }
	
	int end = max(n - m, neg);
	
	int it = 0, cur = 0, sum = 0;
	while (it < end) {
		if (cur + a[it] < 0) { sum -= cur; a[it - 1] = cur; break; }
		cur += a[it++];
		sum += cur;
	}

	cout << end << '\n';
	
	if (it < end) {
		for (int i = 0; i < m; i++) {
			cur = 0;
			for (int j = i + it - 1; j < end; j += m) {
				cout << j << ' ';
				cur += a[j];
				sum += cur;
			}
		}
	}
	
	cout << sum;
}
