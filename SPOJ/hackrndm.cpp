#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int a[n];
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; a[i] = x;
		if (m.find(x) == m.end()) m[x] = 1;
		else m[x]++;
	}
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (m.find(a[i] - 2) != m.end()) cnt += m[a[i] - 2];
	}
	
	cout << cnt;
}
