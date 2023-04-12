#include <bits/stdc++.h>
using namespace std;
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();
	int n, m, ans = 0; cin >> n;
	int a[n], b[n]; arrPut(a); arrPut(b);
	m = b[n - 1];
	ans = a[n - 1] * m;
	for (int i = n - 2; i >= 0; i--) {
		m = max(b[i], m);
		ans += a[i] * m;
	}
	cout << ans;
}
