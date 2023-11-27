#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

int n, t, a;
vector<pair<int, int>> v;
__gnu_pbds::gp_hash_table<int, int> del;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		if (t == 1) {
			cin >> a;
			v.push_back({a, i});
		} else if (t == 2) {
			cin >> a;
			del[a] = i;
		} else if (t == 3) {
			while (!v.empty() && v.back().second <= del[v.back().first]) v.pop_back();
			v.pop_back(); 
		} else {
			while (!v.empty() && v.back().second <= del[v.back().first]) v.pop_back();
			cout << (v.empty() ? -1 : v.back().first) << '\n';
		}
	}
}
