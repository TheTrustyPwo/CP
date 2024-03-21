#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, g[1005][1005];
int vpre[1005][1005], hpre[1005][1005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> g[i][j];
	for (int i = 1; i <= n; i++) {
		int cur = 0;
		for (int j = 1; j <= m; j++) {
			cur += a[i][j];
			if (cur < 0) cur = 0;
			vpre[i][j] = cur;'
		}
		for (int j = m; j >= 1; j--) {
			vpre[i][j].first.second = vpre[i][j + 1].first.second + g[i][j];
			vpre[i][j].second.second = max(vpre[i][j + 1].second.second, vpre[i][j].first.second);
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			hpre[i][j].first.first = hpre[i - 1][j].first.first + g[i][j];
			hpre[i][j].second.first = max(hpre[i - 1][j].second.first, hpre[i][j].first.first);
		}
		for (int i = n; i >= 1; i--) {
			hpre[i][j].first.second = hpre[i + 1][j].first.second + g[i][j];
			hpre[i][j].second.second = max(hpre[i + 1][j].second.second, hpre[i][j].first.second);
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		int vmx = max(vpre[i][j].second.first, vpre[i][j].second.second);
		int hmx = max(hpre[i][j].second.first, hpre[i][j].second.second);
		ans = max(ans, vmx + hmx - g[i][j]);
	}

	cout << ans;
}
