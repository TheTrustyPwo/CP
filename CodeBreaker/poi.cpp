#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, t, p; cin >> n >> t >> p; p--;
	bool res[n][t];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < t; j++)
			cin >> res[i][j];
	
	int points[t];
	for (int i = 0; i < t; i++) {
		int x = 0;
		for (int j = 0; j < n; j++)
			if (!res[j][i]) x++;
		points[i] = x;
	}
	
	int scores[n], solved[n];
	for (int i = 0; i < n; i++) {
		int x = 0, y = 0;
		for (int j = 0; j < t; j++)
			if (res[i][j]) x += points[j], y++;
		scores[i] = x, solved[i] = y;
	}
	
	cout << scores[p] << ' ';
	pair<pair<int, int>, int> ranks[n];
	for (int i = 0; i < n; i++)
		ranks[i] = make_pair(make_pair(scores[i], solved[i]), n - i);
	sort(ranks, ranks + n, greater<pair<pair<int, int>, int>>());
	
	for (int i = 0; i < n; i++)
		if (ranks[i].second == n - p) cout << i + 1;
}
