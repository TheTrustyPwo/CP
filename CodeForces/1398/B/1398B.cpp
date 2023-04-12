#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		vector<int> v;
		int cnt = 0;
		for (char ch : s)
			if (ch == '0') v.push_back(cnt), cnt = 0;
			else cnt++;
		if (cnt > 0) v.push_back(cnt);
		
		sort(v.begin(), v.end(), greater<int>());
		int ans = 0;
		for (int i = 0; i < v.size(); i += 2) ans += v[i];
		cout << ans << '\n';
	}
}
