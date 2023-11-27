#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int q; cin >> q;
	if (q == 1) {
		int n; cin >> n;
		cout << "Tarou wo Noriko wa mimashita";
	} else if (q == 2) {
		int n; cin >> n;
		int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++) cout << a[i] << ' ';
	} else if (q == 3) {
		cout << 69;
	} else cout << "toilet";
}
