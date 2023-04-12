#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int cnt[n+5]; memset(cnt, 0, sizeof(cnt));
	set<int> s; for (int i = 1; i <= n + 1; i++) s.insert(i);
	
	for (int i = 0; i < n; i++) {
		int t, x; cin >> t >> x;
		if (x <= n) {
			if (t == 1) {
				if (++cnt[x] > 0) s.erase(x);
			} else {
				if (cnt[x]) cnt[x]--;
				if (!cnt[x]) s.insert(x);
			}
		}
		
		cout << *s.begin() - 1 << "\n";
	}
}
