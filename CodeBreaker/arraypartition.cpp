#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, s, l, a[300005], g[300005], dp[300005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s >> l;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	multiset<int> st; int p = 1;
	for (int i = 1; i <= n; i++) {
		st.insert(a[i]);
		while (*(--st.end()) - *st.begin() > s)
			st.erase(st.find(a[p++]));
		g[i] = st.size();
	}
	
	dp[0] = 0; multiset<int> w{0}; int x = 0, y = 1;
	for (int i = 1; i <= n; i++) {
		int from = max(i - g[i], 0), to = i - l;
		if (to < from) { dp[i] = 1e9; continue; }
		for (int j = y + 1; j <= to; j++) w.insert(dp[j]); y = to;
		for (int j = x; j < from; j++) w.erase(w.find(dp[j])); x = from;
		dp[i] = (w.empty() ? 1e9 : *w.begin() + 1);
	}

	cout << (dp[n] == 1e9 ? -1 : dp[n]);
}
