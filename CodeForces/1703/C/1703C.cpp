#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) {
			int m, cnt = 0; cin >> m;
			for (int i = 0; i < m; i++) {
				char ch; cin >> ch;
				if (ch == 'D') cnt++;
				else cnt--;
			}
			a[i] = (a[i] + cnt + 100) % 10;
		}
		for (int i = 0; i < n; i++) cout << a[i] << ' ';
		cout << '\n';
	}
}
