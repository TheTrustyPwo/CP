#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 500005;

int n, q;

unordered_set<int> boxes[MAXN];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		boxes[i].insert(i);
	}
	
	while (q--) {
		int t, p, q; cin >> t;
		if (t == 1) {
			cin >> p >> q;
			if (boxes[p].size() < boxes[q].size()) swap(p, q);
			for (int i : boxes[q]) boxes[p].insert(i);
			// boxes[q].clear();
		} else if (t == 2) {
			cin >> p >> q;
			boxes[p].erase(p);
			boxes[q].insert(p);
		} else if (t == 3) {
			cin >> p;
			int sum = 0;
			for (const int x : boxes[p]) sum += x;
			cout << boxes[p].size() << ' ' << sum << "\n";
		}
	}
}
