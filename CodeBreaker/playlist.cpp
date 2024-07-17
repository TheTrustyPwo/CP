#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		x += a; y += b;
	}
	x += (y / 60);
	y %= 60;
	cout << x << ' ' << y;
}
