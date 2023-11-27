#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	pair<int, int> a[n];
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	
	sort(a, a + n, greater<pair<int, int>>());
	
	int useful = 0, mx = -1;
	for (int i = 0; i < n; i++) {
		if (a[i].second > mx) {
			mx = a[i].second;
			useful++;
		}
	}
	
	cout << useful;
}
