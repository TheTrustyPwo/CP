#include <bits/stdc++.h>
using namespace std;
#define int long long

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return (a.second * b.first) > (a.first * b.second);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	pair<int, int> a[n]; for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	stable_sort(a, a + n, &cmp);
	for (int i = 0; i < n; i++) cout << a[i].first << ' ' << a[i].second << '\n';
}
