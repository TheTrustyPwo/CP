#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[2 * n]; for (int i = 0; i < 2 * n; i++) cin >> a[i];
	bool b = true;
	for (int i = 1; i < 2 * n; i++) if (a[i] < a[i - 1]) b = false;
	cout << (b ? "Yes" : "No");
}
