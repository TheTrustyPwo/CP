#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b, c, d; cin >> a >> b >> c >> d;
	int e[a], f[b], g[c], h[d];
	for (int i = 0; i < a; i++) cin >> e[i];
	for (int i = 0; i < b; i++) cin >> f[i];
	for (int i = 0; i < c; i++) cin >> g[i];
	for (int i = 0; i < d; i++) cin >> h[i];
	
	unordered_map<int, pair<int, int>> m;
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
			m[e[i] + f[j]] = make_pair(e[i], f[j]);
			
	for (int i = 0; i < c; i++)
		for (int j = 0; j < d; j++)
			if (m.find(-g[i]-h[j]) != m.end()) { cout << m[-g[i]-h[j]].first << ' ' << m[-g[i]-h[j]].second << ' ' << g[i] << ' ' << h[j]; return 0; }
}
