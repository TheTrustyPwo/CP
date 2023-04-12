#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1000005;

int n, a[MAXN];
vector<pair<int, int>> v;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	
	int ind = 1; a[0] = -1;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (a[ind - 1] == x) continue;
		a[ind] = x;
		ind++;
	}
	
	a[ind++] = -1;
	for (int i = 1; i < ind - 1; i++)
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) v.push_back(make_pair(a[i], 1));
		else if (a[i] < a[i - 1] && a[i] < a[i + 1]) v.push_back(make_pair(a[i], -1));
	
	int prev = -1e9, cur = 0, ans = 0;
	sort(v.begin(), v.end(), greater<pair<int, int>>());
	for (const auto u : v){
		if (u.first != prev) ans = max(ans, cur);
		prev = u.first;
		cur += u.second;
	}
	
	cout << ans;
}
