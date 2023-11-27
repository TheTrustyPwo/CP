#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	
	int mn = *min_element(a, a + n);
	int cnt = 0;
	for (int i = 0; i < n; i++) if (a[i] > mn) cnt++;
	cout << mn * n + cnt;
}
