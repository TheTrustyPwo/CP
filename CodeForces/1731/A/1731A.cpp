#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int s = 1;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			s *= a;
		}
		
		cout << (s + n - 1) * 2022 << "\n";
	}
}
