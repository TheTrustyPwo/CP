#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, d, k, cnt = 0; cin >> n >> d >> k;
	int e[n]; for (int i = 0; i < n; i++) cin >> e[i];
	sort(e, e + n);
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (d <= 0) {
			cout << cnt - 1;
			return 0;
		}
		if (k == 0) {
			int u = q.front();
			if (!q.empty() && d - e[i] / 2 - u + u / 2 >= 0) {
				q.pop();
				q.push(e[i] / 2);
				d = d - e[i] / 2 - u + u / 2;
			} else {
				cout << cnt;
				return 0;
			}
		} else {
			q.push(e[i] / 2);
			d -= e[i] / 2;
			k--; cnt++;
		}
	}
	cout << cnt;
}
