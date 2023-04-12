#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, x, y; cin >> n >> x >> y;
	int a[n], b[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	
	pair<int, int> c[n];
	for (int i = 0; i < n; i++) c[i] = make_pair(a[i] - b[i], i);
	sort(c, c + n);
	
	int sum = 0;
	for (int i = 0; i < y; i++) sum += b[c[i].second];
	for (int i = y; i < n; i++) sum += a[c[i].second];
	cout << sum;
}
