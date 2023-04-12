#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if (v.empty() || v.back() != x) v.push_back(x);
		}
		
		int cnt = 0;
		for (int i = 0; i < (int) v.size(); i++)
			if ((i == 0 || v[i - 1] > v[i]) && (i == (int) v.size() - 1 || v[i + 1] > v[i])) cnt++;
			
		cout << (cnt == 1 ? "YES\n" : "NO\n");
	}
}
