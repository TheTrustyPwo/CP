#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, c, a, q; cin >> n >> c;
	set<pair<int, int>> s;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		s.insert(make_pair(a, i));
	}
	while (c--) {
		cin >> q;
		auto it = s.lower_bound(make_pair(q, -1));
		if (it == s.end() || (it != s.begin() && (q - (prev(it))->first <= it->first - q))) it--;
		cout << it->second << endl;
		s.erase(it);
	}
}
