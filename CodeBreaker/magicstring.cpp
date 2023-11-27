#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[26]; for (int i = 0; i < 25; i++) a[i] = 0;
	while (n--) {
		char ch; cin >> ch;
		int x = (int)(ch - 'a');
		int ans = 0;
		for (int i = 0; i < x; i++) ans += a[i];
		cout << ans << '\n';
		a[x]++;
	}
}
