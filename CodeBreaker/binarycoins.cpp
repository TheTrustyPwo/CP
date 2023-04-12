#include <bits/stdc++.h>
using namespace std;
#define range(it, start, end) for (int it = start; it < end; it++)
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int unsigned long long
int32_t main() {
	setup();
	int n; cin >> n;
	int ans = 0;
	while (n) {
		ans += (n & 1);
		n >>= 1;
	}
	cout << ans;
}
