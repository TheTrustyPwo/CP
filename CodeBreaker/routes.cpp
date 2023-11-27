#include <bits/stdc++.h>
using namespace std;
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int dir1[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int dir2[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

int32_t main() {
	setup();
	int l, n; cin >> l >> n;
	pair<int, int> a[n];
	range(i, 0, n) cin >> a[i].first >> a[i].second;
	sort(a, a + n);
	range(i, 0, n) a[i] = make_pair(a[i].first - a[i].second, a[i].first + a[i].second);
	range(i, 0, n) cout << a[i].first << " " << a[i].second << "  ";
	int ans = 1, cur = a[0].second;
	range(i, 1, n) {
		auto *it = upper_bound(a + i, a + n, make_pair(cur, 0));
		cur = (*it).second;
		cout << cur << endl;
		ans++;
		if (cur >= l) {
			cout << ans;
			return 0;
		}
	}
	cout << -1;
}
