#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int x1, x2, x3, y1, y2, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		if ((x1 == x2 || x2 == x3 || x1 == x3) && (y1 == y2 || y1 == y3 || y2 == y3))cout << "NO\n";
		else cout << "YES\n";
	}
}
