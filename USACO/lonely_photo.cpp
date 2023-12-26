#include <bits/stdc++.h>
using namespace std;
#define int long long

int n; string s;
int first[500005], second[500005], same[500005];
vector<pair<int, int>> g, h;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s;
	fill(first, first + n, n); fill(second, second + n, n); fill(same, same + n, n);
	for (int i = 0; i < n; i++) {
		vector<pair<int, int>> tmp{};
		if (s[i] == 'G') {
			g.push_back(make_pair(i, 1));
			while (!h.empty()) {
				if (h.back().second == 1) {
					first[h.back().first] = i;
					tmp.push_back(make_pair(h.back().first, 2));
				} else if (h.back().second == 2) second[h.back().first] = i;
				else same[h.back().first] = i;
				h.pop_back();
			}
			for (auto p : tmp) h.push_back(p);
			h.push_back(make_pair(i, 3));
		} else {
			h.push_back(make_pair(i, 1));
			while (!g.empty()) {
				if (g.back().second == 1) {
					first[g.back().first] = i;
					tmp.push_back(make_pair(g.back().first, 2));
				} else if (g.back().second == 2) second[g.back().first] = i;
				else same[g.back().first] = i;
				g.pop_back();
			}
			for (auto p : tmp) g.push_back(p);
			g.push_back(make_pair(i, 3));
		}
	}

	int ans = 0;
	for (int i = 0; i < n - 2; i++) {
		int s = max(first[i], i + 2), f = max(second[i], same[i]);
		ans += max(f - s, 0LL);
	}
	cout << ans;
}
