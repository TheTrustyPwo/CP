#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int q; cin >> q;
	deque<pair<int, int>> dq;
	while (q--) {
		int t, a, b; cin >> t;
		if (t == 1) {
			cin >> a >> b;
			dq.emplace_back(a, b);
		} else {
			cin >> a; int sum = 0;
			while (!dq.empty()) {
				int h = dq.front().first, n = dq.front().second;
				if (a >= n) { sum += h * n; dq.pop_front(); a -= n; }
				else {
					dq.front().second -= a;
					sum += h * a;
					break;
				}
			}
			cout << sum << '\n';
		}
	}
}
