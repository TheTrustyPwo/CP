#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	set<int> st;
	int a[n];
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		st.insert(x);
		a[i] = st.size();
	}
	while (q--) {
		int x; cin >> x;
		cout << a[x - 1] << ' ';
	}
}
