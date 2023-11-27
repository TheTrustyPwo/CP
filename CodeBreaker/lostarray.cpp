#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, ans[100005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m; fill(ans, ans + n + 1, 0);
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		ans[a] = max(ans[a], c);
		ans[b] = max(ans[b], c);
	}
	
	for (int i = 1; i <= n; i++)
		cout << (ans[i] == 0 ? 1000000000 : ans[i]) << ' ';
}
