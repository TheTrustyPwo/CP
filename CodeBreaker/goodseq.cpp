#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, ans = 0; cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		m[a]++;
	}
	for (auto const &[key, value] : m) {
		if (key < value) ans += (value - key);
		else if (key > value) ans += value;
	}
	cout << ans;
}
