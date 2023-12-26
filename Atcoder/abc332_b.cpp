#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int k, g, m; cin >> k >> g >> m;
	int gc = 0, mc = 0;
	while (k--) {
		if (gc == g) gc = 0;
		else if (mc == 0) mc = m;
		else {
			int req = g - gc;
			int transfer = min(req, mc);
			mc -= transfer;
			gc += transfer;
		}
	}
	cout << gc << ' ' << mc;
}
