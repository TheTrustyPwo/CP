#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	double x = ((double) a.second) / a.first;
	double y = ((double) b.second) / b.first;
	return x < y;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	pair<int, int> a[n];
	for (int i = 0; i < n; i++) cin >> a[i].first;
	for (int i = 0; i < n; i++) cin >> a[i].second;
	sort(a, a + n, &cmp);
	
	int alert = 0, enjoy = 0;
	for (int i = 0; i < n; i++) {
		if (alert + a[i].first > k) continue;
		enjoy += (alert * a[i].second);
		alert += a[i].first;
	}
	
	cout << enjoy;
}
