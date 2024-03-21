#include <bits/stdc++.h>
using namespace std;
#define int long long

int n; vector<int> a{-1}, b{-1};
int memo[5005][5005];

int cl(int x, int y) {
	return (x + y - 1) / y;
}

int solve(int x, int y) {
	if (x == 0 && y == 0) return 0;
	if (memo[x][y] != 0) return memo[x][y];
	int level = 1 + x + 2 * y;
	memo[x][y] = 1e18;
	if (x > 0) memo[x][y] = min(memo[x][y], cl(a[x], level - 1) + solve(x - 1, y));
	if (y > 0) memo[x][y] = min(memo[x][y], cl(b[y], level - 2) + solve(x, y - 1));
	return memo[x][y];
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int h, e; cin >> h >> e;
		if (e == 1) a.push_back(h);
		else b.push_back(h);
	}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	int ans = solve(a.size() - 1, b.size() - 1);
	cout << ans;
}
