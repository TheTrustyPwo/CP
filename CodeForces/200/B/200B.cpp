#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	double n; cin >> n;
	double ans = 0;
	for (int i = 0; i < n; i++) {
		double x; cin >> x;
		ans += x;
	}
	cout << ans / n;
}
