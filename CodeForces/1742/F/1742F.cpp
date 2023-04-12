#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int q; cin >> q;
		int cnt1 = 1, cnt2 = 1; bool b1 = false, b2 = false;
		while (q--) {
			int tp, k; string x; cin >> tp >> k >> x;
			for (const char ch : x) {
				if (tp == 1) {
					if (ch == 'a') cnt1 += k;
					else b1 = true;
				} else {
					if (ch == 'a') cnt2 += k;
					else b2 = true;
				}
			}
			
			if (b2 || (!b1 && cnt2 > cnt1)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
