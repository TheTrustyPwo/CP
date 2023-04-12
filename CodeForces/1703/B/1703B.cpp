#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		unordered_set<char> s;
		for (int i = 0; i < n; i++) {
			char ch; cin >> ch;
			s.insert(ch);
		}
		
		cout << n + s.size() << '\n';
	}
}
