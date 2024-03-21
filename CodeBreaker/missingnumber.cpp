#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	bool ok[n + 1]{};
	for (int i = 1; i < n; i++) { int x; cin >> x; ok[x] = 1; }
	for (int i = 1; i <= n; i++) if (!ok[i]) {
		cout << i;
		return 0;
	}
}
