#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, pref_sum[205][205];
bool grid[205][205];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			grid[i][j] = s[j] == 'X';
			pref_sum[i + 1][j + 1] = pref_sum[i][j + 1] + pref_sum[i + 1][j];
			pref_sum[i + 1][j + 1] -= pref_sum[i][j];
			pref_sum[i + 1][j + 1] += grid[i][j];
		}
	}

	int max_area = 0;

	for (int c1 = 0; c1 < m; c1++) {
		for (int c2 = 0; c2 < m; c2++) {
			int prev = -1;
			for (int r = 0; r < n; r++) {
				bool emp = (pref_sum[r + 1][c2 + 1] - pref_sum[r][c2 + 1] - pref_sum[r + 1][c1] + pref_sum[r][c1]) == 0;
				if (emp) max_area = max(max_area, c2 - c1 + 1);
				if (emp && prev != -1) max_area = max(max_area, (r - prev + 1) * (c2 - c1 + 1));
				if (grid[r][c1] || grid[r][c2]) prev = -1;
				if (emp && prev == -1) prev = r;
			}
		}
	}

	cout << max_area << endl;
}
