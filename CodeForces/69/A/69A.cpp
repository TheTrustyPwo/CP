#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < n; i++) {
		int x, y, z; cin >> x >> y >> z;
		a += x; b += y; c += z;
	}
	cout << (a == 0 && b == 0 && c == 0 ? "YES" : "NO");
}
