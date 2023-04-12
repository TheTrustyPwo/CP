#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	if (n % m == 0) {
		for (int i = 0; i < n; i++) cout << n / m << ' ';
	} else {
		for (int i = 1; i < m; i++) cout << 1 << ' ';
		for (int i = 0; i < n - m + 1; i++) cout << n - m + 1 << ' ';
	}
}
