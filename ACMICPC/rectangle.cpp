#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> v;
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (mp[x]) v.push_back(x), mp[x] = 0;
		else mp[x] = 1;
	}
	
	sort(v.begin(), v.end(), greater<int>());
	if (v.size() < 2) cout << 0;
	else cout << v[0] * v[1];
}
