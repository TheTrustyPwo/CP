#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	pair<int, int> a[n];
	for (int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;
	sort(a, a + n);
	int t = 0;
	for (int i = 0; i < n; i++) {
		t += a[i].second;
		if (t > a[i].first) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
}
