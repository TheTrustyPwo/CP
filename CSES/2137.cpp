#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC target("popcnt")

int n;
bitset<3005> b[3005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> b[i];
	int ans = 0;
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
		int x = (b[i] & b[j]).count();
		ans += x * (x - 1);
	}
	cout << (ans >> 1);
}
