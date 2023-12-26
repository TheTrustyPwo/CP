#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	vector<int> a[m]; int ptr[m]; fill(ptr, ptr + m, 0);
	bool ok[m]; memset(ok, 1, sizeof(ok));
	for (int i = 0; i < m; i++) {
		int k, x; cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> x;
			a[i].push_back(x);
		}
	}
	
	unordered_map<int, int> mp;
	while (true) {
		bool change = 0;
		for (int i = 0; i < m; i++) {
			if (ok[i] && ptr[i] < a[i].size()) {
				int val = a[i][ptr[i]];
				if (mp[val] == 0) {
					mp[val] = i + 1;
					ok[i] = false;
				} else {
					ptr[i]++, ptr[mp[val] - 1]++;
					ok[mp[val] - 1] = 1;
					mp[val] = 0;
					change = 1;
				}
			}
		}
		if (!change) break;
	}
	
	bool ans = 1;
	for (int i = 0; i < m; i++) ans & (ptr[i] == a[i].size());
	cout << (ans ? "YES" : "NO");
}
