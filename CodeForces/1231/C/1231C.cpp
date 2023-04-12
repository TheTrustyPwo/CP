#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.first * a.second > b.first * b.second;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	int a[n][m], sum = 0;
	vector<pair<int, int>> empty;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			sum += a[i][j];
			if (a[i][j] == 0) empty.push_back(make_pair(i, j));
		}
	}
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m - 1; j++)
			if (a[i][j] >= a[i][j + 1] && a[i][j + 1] != 0)
				return puts("-1");
	
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] >= a[i + 1][j] && a[i + 1][j] != 0)
				return puts("-1");
	
	sort(empty.begin(), empty.end(), &cmp);
	
	for (const pair<int, int> p : empty) {
		int lower = max(a[p.first - 1][p.second], a[p.first][p.second - 1]);
		int upper = min(a[p.first + 1][p.second], a[p.first][p.second + 1]);
		if (upper - lower <= 1) return puts("-1");
		a[p.first][p.second] = upper - 1;
		sum += upper - 1;
	}
	
	cout << sum;
}
