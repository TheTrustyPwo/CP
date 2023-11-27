#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int, int>> v;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q; cin >> n >> q;
	int t, x;
	for (int i = 0; i < q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> x;
			int prev = (v.empty() ? 0 : v.back().second);
			v.push_back({x, max(x, prev)});
		} else {
			v.pop_back();
		}
	}
	
	cout << (v.empty() ? 0 : v.back().second) << '\n';
}
