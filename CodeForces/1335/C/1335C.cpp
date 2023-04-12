#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		unordered_map<int, int> mp;
		unordered_set<int> s;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			mp[x]++;
			s.insert(x);
		}
		
		int freq = 0;
		for (auto it : mp) freq = max(freq, it.second);
		
		int sz = s.size();
		cout << max(min(freq, sz - 1), min(freq - 1, sz)) << '\n';
	}
}
