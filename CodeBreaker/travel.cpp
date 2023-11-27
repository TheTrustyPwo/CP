#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k, mn = 0, mx = 0; cin >> n >> k;
	vector<int> a, b;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x <= k) a.push_back(x);
		else b.push_back(x);
		mx += abs(x - k);
	}
	
	a.push_back(k); b.push_back(k);
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end());
	
	for (size_t i = 1; i < a.size(); i++) mn += abs(a[i] - a[i - 1]);
	for (size_t i = 1; i < b.size(); i++) mn += (b[i] - b[i - 1]);
	
	cout << mn << '\n' << mx;
}
