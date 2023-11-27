#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, x, a[1005], b[1005], c[1005];
vector<int> m;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) cin >> c[i];
	
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) m.push_back(a[i] * b[j]);
	sort(c, c + n);
	
	int diff = 1e18, ans;
	for (const int &i : m) {
		int t = x - i;
		auto it = lower_bound(c, c + n, t);
		int v = (it - c != n && (it - c == 0 || *it - t <= t - *(it-1))) ? *it : *(it-1);
		if (abs(v - t) < diff || v - t == diff) {
			diff = abs(v - t);
			ans = i + v;
		}
	}
	
	cout << ans;
}
