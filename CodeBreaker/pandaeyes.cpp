#include <bits/stdc++.h>
using namespace std;
#define range(it, start, end) for (ll it = start; it < end; it++)
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int dir1[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int dir2[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

int32_t main() {
	setup();
	ll n; cin >> n;
	pair<int, int> a[n];
	range(i, 0, n) cin >> a[i].second >> a[i].first;
	sort(a, a + n);
	ll ans = 1, cur = a[0].first;
	range(i, 1, n) {
		if (a[i].second >= cur) {
			cur = a[i].first;
			ans++;
		}
	}
	cout << ans;
}
