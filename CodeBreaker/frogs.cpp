#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, k; cin >> n >> m >> k;
	int d[m]; for (int i = 0; i < m; i++) cin >> d[i];
	int a[k]; for (int i = 0; i < k; i++) cin >> a[i];
	
	vector<pair<int, int>> v;
	for (int i = 0; i < m; i++) {
		int smash = 0;
		for (int j = 0; j < k; j++)
			if (a[j] % d[i] == 0) smash++;
		v.push_back(make_pair(smash, i));
	}
	
	sort(v.begin(), v.end());
	int cnt = 0, mn = v[0].first;
	for (auto p : v)
		if (p.first == mn) cnt++;
		else break;
	cout << cnt << '\n';
	for (auto p : v)
		if (p.first == mn) cout << p.second + 1 << ' ';
		else break;
}
