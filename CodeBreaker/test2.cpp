#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	unordered_set<int> a, b;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		a.insert(x);
		b.insert(x);
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		if (a.find(x) != a.end()) cnt++;
		b.insert(x);
	}
	
	int ans = n - b.size() + cnt;
	cout << ans;
}
