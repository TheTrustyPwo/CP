#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++) {
		if (a[i] % 2 != 0) {
			cout << "NO";
			return 0;
		}
		a[i + 1] += (a[i] / 2);
		a[i] = 0;
	}
	
	if (a[n - 1] % 2 == 0) cout << "YES";
	else cout << "NO";
}
