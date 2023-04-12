#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n, odd = 0, even = 0; cin >> n;
		set<int> s;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if (x & 1) odd++;
			else even++;
			s.insert(x);
		}
		
		if (n & 1) { cout << "NO\n"; continue; }
		if (odd % 2 == 0 && even % 2 == 0) { cout << "YES\n"; continue; }
		
		int prev = *s.begin(); bool flag = false;
		for (const int x : s) {
			if (x - prev == 1) { flag = true; break; }
			prev = x;
		}
		
		cout << (flag ? "YES\n" : "NO\n");
	}
}
