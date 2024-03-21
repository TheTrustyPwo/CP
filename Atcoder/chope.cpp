#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, l; cin >> n >> l;
	int idx = 1; bool b = true;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (idx >= l && x == 2) b = false;
		idx += x + 1;
	}
	if (b) cout << "Yes";
	else cout << "No";
}
