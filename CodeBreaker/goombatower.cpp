#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	set<int> s; for (int i = 1; i <= n; i++) s.insert(i);
	while (q--) {
		char ch; int x; cin >> ch >> x;
		auto it = s.begin();
		for (int i = 1; i < x; i++) it++;
		if (ch == 'D') {
			s.erase(it);
		} else cout << *it << '\n';
	}
}
