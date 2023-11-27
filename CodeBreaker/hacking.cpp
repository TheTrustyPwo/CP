#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int upload[500005], target[500005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	while (m--) {
		int t, x, y; cin >> t;
		if (t == 1) {
			cin >> x >> y;
			upload[x]++;
			target[y]++;
		} else if (t == 2) {
			cin >> x >> y;
			upload[x]--;
			target[y]--;
		} else if (t == 3) {
			cin >> x;
			cout << target[x] << '\n';
		} else {
			cin >> x;
			cout << upload[x] << '\n';
		}
	}
}
